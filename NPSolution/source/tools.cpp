#include "tools.h"
#include <gsl/gsl_histogram.h>
#include <gsl/gsl_movstat.h>
#include <math.h>  

gsl_vector* gaussSmooth(gsl_vector* x, float s, int w) {
    gsl_vector* y = gsl_vector_alloc(x->size);
    gsl_vector* k = gsl_vector_alloc(w);
    gsl_filter_gaussian_workspace* gauss_p = gsl_filter_gaussian_alloc(w);
    gsl_filter_gaussian_kernel(s, 0, 1, k);
    gsl_filter_gaussian(GSL_FILTER_END_PADVALUE, s, 0, x, y, gauss_p);
    gsl_vector_free(k);
    gsl_filter_gaussian_free(gauss_p);
    return y;
}   

gsl_vector* meanSmooth(gsl_vector* x, int w) {
    gsl_movstat_workspace* mean_p = gsl_movstat_alloc(w);
    gsl_vector* y = gsl_vector_alloc(x->size);
    gsl_movstat_mean(GSL_MOVSTAT_END_PADVALUE, x, y, mean_p);
    gsl_movstat_free(mean_p);
    return y;
}

std::vector<Peak> findPeak(double* x, size_t size, int t, double& sd, double& mean) {
    stdDevBaseline(x, size, sd, mean);
    gsl_vector* xb = gsl_vector_alloc(size);
    int d = 1;
    if (mean < 0) {
        d = -1;
        for (int i = 0; i < size; i++) {
            x[i] *= -1;
        }     
    }
    moveBaseline(x, size, xb, mean, sd);
    double* b = xb->data;
    std::vector<Peak> res;
    double th = sd * t;
    bool flag = false;
    for (int i = 0; i < size; i++) {
        if (x[i] < b[i] - th && !flag) {
            for (int j = i; j >= 1; j--) {
                if (x[j] >= b[j] || x[j] >= x[j - 1] && x[j] <= x[j + 1] && abs(x[j]-b[j]) < sd) {
                    if (res.size() > 0 && j <= res.back().end + 400) {
                        flag = true;
                        break;
                    }   
                    Peak peak = { 0,0,0,0,0,0,0,0,0,0 };
                    res.push_back(peak);
                    flag = true;
                    res.back().start = j;
                    break;
                }
            }
        }
        if (flag && x[i]>=b[i]) {
            int ps = 0;
            int pe = 0;
            for (int j = i; j >= res.back().start && j < size - 1 && j >= 1; j--) {
                if (x[j] <= x[j - 1] && x[j] <= x[j + 1] && x[j] < b[j] - 0.5*th) {
                    pe = j + 1;
                    res.back().end = j;
                    break;
                }
            }
            for (int j = res.back().start; j <=i && j < size - 1 && j >= 1; j++) {
                if (x[j] <= x[j - 1] && x[j] <= x[j + 1] && x[j] < b[j] - th) {
                    ps = j;
                    break;
                }
            }
            res.back().currentmax = 0;
            for (int j = ps; j < pe; j++) {
                res.back().currentmax += x[j];
            }
            res.back().currentmax /= d * (pe - ps);
            res.back().currentbase = (b[res.back().start] + b[res.back().end]) / 2 * d;
            if (res.back().end == 0 || res.back().currentmax == 0 || d * (res.back().currentbase - res.back().currentmax) < th)
                res.pop_back();
            else {
                float stdDev = 0;
                int num = 0;
                for (int j = ps; j < pe; j++) {
                    stdDev += (d * x[j] - res.back().currentmax) * (d * x[j] - res.back().currentmax);
                    num++;
                }
                for (int j = res.back().start; j >= 0 && j >= res.back().start - pe + ps; j--) {
                    stdDev += (d * x[j] - res.back().currentbase) * (d * x[j] - res.back().currentbase);
                    num++;
                }
                for (int j = i; j < size && j < pe + pe - ps; j++) {
                    stdDev += (d * x[j] - res.back().currentbase) * (d * x[j] - res.back().currentbase);
                    num++;
                }
                stdDev = sqrt(stdDev / num);
                res.back().score = abs(stdDev - sd) / sd;
            }            
            flag = false;
        }
    }
    if (mean < 0) 
        for (int i = 0; i < size; i++) 
            x[i] *= -1;
    gsl_vector_free(xb);
    return res;
}

void stdDevBaseline(double* x, size_t size, double& stdDev, double& baseline) {
    size_t s = 0;
    size_t e;
    if (s + 100000 >= size) {
        e = size;
        s = (e >= 100000) ? e - 100000 : 0;
    }
    else
        e = s + 100000;
    gsl_histogram* h = gsl_histogram_alloc(175);
    float xmin = x[s];
    float xmax = x[e];
    for (int i = s + 1; i < e; i++) {
        xmin = (x[i] < xmin) ? x[i] : xmin;
        xmax = (x[i] > xmax) ? x[i] : xmax;
    }
    gsl_histogram_set_ranges_uniform(h, xmin, xmax);
    for (int i = s; i < e; i++)
        gsl_histogram_increment(h, x[i]);
    double maxbin = gsl_histogram_max_val(h);
    for (int i = 0; i < h->n; i++) {
        if (h->bin[i] >= maxbin * 0.05) {
            xmin = h->range[i];
            break;
        }
    }
    for (int i = h->n - 1; i >= 0; i--) {
        if (h->bin[i] >= maxbin * 0.05) {
            xmax = h->range[i];
            break;
        }
    }
    gsl_histogram_free(h);
    baseline = 0;
    int n = 0;
    for (int i = s; i < e; i++) {
        if (x[i] >= xmin && x[i] <= xmax) {
            baseline += x[i];
            n++;
        }
    }
    baseline /= n;
    stdDev = 0;
    n = 0;
    for (int i = s; i < e; i++) {
        if (x[i] >= xmin && x[i] <= xmax) {
            stdDev += (x[i] - baseline) * (x[i] - baseline);
            n++;
        }
    }
    stdDev = sqrt(stdDev / n);
    return;
}

void moveBaseline(double* buff, size_t size, gsl_vector* xb, double baseline, double stdDev) {
    gsl_movstat_workspace* w = gsl_movstat_alloc(10000);
    gsl_vector_view x = gsl_vector_view_array(buff, size);
    gsl_vector* xsd = gsl_vector_alloc(size);
    gsl_movstat_mean(GSL_MOVSTAT_END_PADVALUE, &x.vector, xb, w);
    gsl_movstat_sd(GSL_MOVSTAT_END_PADVALUE, &x.vector, xsd, w);
    baseline = abs(baseline);
    for (int i = 0; i < size; i++)
        if (gsl_vector_get(xsd, i) < 2 * stdDev && abs(gsl_vector_get(xb, i) - baseline) <= 2 * stdDev)
            baseline = gsl_vector_get(xb, i);
        else 
            gsl_vector_set(xb, i, baseline);
    gsl_vector_free(xsd);
    gsl_movstat_free(w);
    return;
}

float Efield(Physical& p) {
    float e;
    e = p.vol * (p.er * p.lp / (M_PI * p.rp * p.rp)) / (p.er * p.lp / (M_PI * p.rp * p.rp) + p.er / (2 * p.rp)) / p.lp;
    return e;
}

float gvalue(Physical& p) {
    float g;
    g = 1 / (M_PI * p.rp * p.rp * (p.lp + 1.6 * p.rp));
    return g;
}

void volum_shape(float& shape_o, float& volume_o, float& shape_p, float& volume_p, float I_min, float I_max, float g, std::vector<float>& m_o, std::vector<float>& y_o, std::vector<float>& m_p, std::vector<float>& y_p) {
    float F_max_o = I_max / I_min + 0.5;
    float F_min_p = I_min / I_max + 0.5;
    auto it = std::lower_bound(y_o.begin(), y_o.end(), F_max_o);
    shape_o = ((it - y_o.begin()) < y_o.size()) ? m_o[it - y_o.begin()] : 0;
    it = std::lower_bound(y_p.begin(), y_p.end(), F_min_p);
    shape_p = ((it - y_p.begin()) < y_p.size()) ? m_p[it - y_p.begin()] : 0;
    volume_o = I_max / (g * F_max_o * 1e-27);
    volume_p = I_min / (g * F_min_p * 1e-27);
    return;
}

void oblate(std::vector<float>& m, std::vector<float>& y) {
    float t;
    float k;
    for (int i = 0; i < 999; i++) {
        k = 0.001 * (i + 1);
        m[998-i] = k;
        y[998-i] = 1/(k * std::acos(k) / pow((1 - k * k), 1.5) - k * k / (1 - k * k));
    }
    return;
}
void prolate(std::vector<float>& m, std::vector<float>& y) {
    float t;
    float k;
    for (int i = 0; i < 999; i++) {
        k = (0.1 * (i + 1)) / 2 + 1;
        m[998-i] = k;
        y[998-i] = 1 / (k * k / (k * k - 1) - k * acosh(k) / pow((k * k - 1), 1.5));
    }
    return;
}