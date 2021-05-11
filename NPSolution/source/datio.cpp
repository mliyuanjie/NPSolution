#include "datio.h" 

void DATIO::open(std::string fn) {
	close();
	if (fn.substr(fn.length() - 3, 3) != "dat")
		return;
	file.open(fn);
	size_t length = file.size();
	if (length == 0)
		return;
	n = length / sizeof(float);
	pos = (float*)file.data();
	interv = pos[0];
	if (interv >= 0 && interv <= 100) {
		interv *= 1000;
		n--;
		pos++;
	}
	else
		interv = 2;
	return;
}

void DATIO::close() {
	if (file.is_open())
		file.close();
	return;
}

std::vector<float> DATIO::data(size_t start, size_t end, size_t skip) {
	if (!file.is_open())
		return std::vector<float>();
	end = (end == 0 || end > n) ? n : end;
	skip = (skip == 0) ? 1 : skip;
	std::vector<float> res((end - start) / skip);
	size_t j = 0;
	for (size_t i = start; i < end; i += skip) {
		res[j] = pos[i];
		j++;
	}
	return res;
}

float DATIO::valmax(size_t start, size_t end) {
	if (!file.is_open())
		return 0;
	end = (end == 0 || end > n) ? n : end;
	float res = pos[start];
	float tmp;
	for (size_t i = start + 1; i < end; i++) {
		tmp = pos[i];
		res = (tmp > res) ? tmp : res;
	}
	return res;
}

float DATIO::valmin(size_t start, size_t end) {
	if (!file.is_open())
		return 0;
	end = (end == 0 || end > n) ? n : end;
	float res = pos[start];
	float tmp;
	for (size_t i = start + 1; i < end; i++) {
		tmp = pos[i];
		res = (tmp < res) ? tmp : res;
	}
	return res;
}

std::pair<float, float> DATIO::valminmax(size_t start, size_t end) {
	if (!file.is_open())
		return std::pair<float, float>(0,0);
	end = (end == 0 || end > n) ? n : end;
	float xmin = pos[start];
	float xmax = xmin;
	float tmp;
	bool direction = false;
	for (size_t i = start + 1; i < end; i++) {
		tmp = pos[i];
		if (tmp < xmin) {
			xmin = tmp;
			direction = false;
		}
		if (tmp > xmax) {
			xmax = tmp;
			direction = true;
		}
	}
	if(direction)
		return std::pair<float, float>(xmin, xmax);
	return std::pair<float, float>(xmax, xmin);
}

float DATIO::at(size_t i) {
	if (i >= n)
		return 0;
	return pos[i];
}

float DATIO::baseline(size_t start, size_t end) {
	float sum = 0;
	int num = 0;
	for (size_t i = start; (i > 0) && (i > (start - 2000)); i--) {
		sum += pos[i];
		num++;
	}
		
	for (size_t i = end; (i < n) && (i < (end + 2000)); i++) {
		sum += pos[i];
		num++;
	}
	return sum / num;
}