#ifndef TOOLS_H
#define TOOLS_H 
#define _USE_MATH_DEFINES

#include <cmath>
#include <vector>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_filter.h>
#include <gsl/gsl_statistics.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_multifit_nlinear.h>
#include <gsl/gsl_spline.h>
#include <gsl/gsl_fft_complex.h>

struct Peak {
	int start;
	int end;
	float currentmax;
	float currentbase;
	float Imax;
	float Imin;
	float volume;
	float shape;
	float residues;
	float score;
};

struct Para {
	float sigma;
	float window;
	float threshold;
	float interval;
	float stdDev;
};

struct Physical {
	float rp = 10;
	float lp = 30;
	float er = 0.046;
	float vol = -0.1;
};

struct FitPara {
	float noise0 = 0;
	float noise1 = 1;
	float noise2 = 500;
	float dipole0 = 550;
	float dipole1 = 0;
	float dipole2 = 30000;
	float imin = 10;
	float imax = 90;
	float ileft = 0;
	float iright = 1;
	float dt0 = 150;
	float dt1 = 2000;
	float mint = 20;
	bool oblate = true;
};

gsl_vector* gaussSmooth(gsl_vector* x, float s, int w);
gsl_vector* meanSmooth(gsl_vector* x, int w);
std::vector<Peak> findPeak(double* x, size_t size, int t, double&, double&);
void stdDevBaseline(double* x, size_t size, double& stdDev, double& baseline);
void moveBaseline(double* x, size_t size, gsl_vector* b, double baseline, double stdDev);
float Efield(Physical& p);
float gvalue(Physical& p);
void oblate(std::vector<float>& m, std::vector<float>& y);
void prolate(std::vector<float>& m, std::vector<float>& y);
void volum_shape(float& shape_o, float& volume_o, float& shape_p, float& volume_p, float I_min, float I_max, float g, std::vector<float>& m_o, std::vector<float>& y_o, std::vector<float>& m_p, std::vector<float>& y_p);


#endif // !TOOLS_H