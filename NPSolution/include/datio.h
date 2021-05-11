#ifndef DATIO_H
#define DATIO_H

#include <string>
#include <vector>
#include <cmath>
#include <boost/iostreams/device/mapped_file.hpp>

class DATIO {
public:
	std::vector<float> data(size_t start = 0, size_t end = 0, size_t skip = 1);
	void close();
	void open(std::string);
	float interval() { return interv; };
	int size() { return n; };
	float valmin(size_t start = 0, size_t end = 0);
	float valmax(size_t start = 0, size_t end = 0);
	float at(size_t);
	float baseline(size_t start, size_t end);
	std::pair<float, float> valminmax(size_t start = 0, size_t end = 0);
private:
	float interv;
	size_t n;
	float* pos;
	boost::iostreams::mapped_file_source file;
};
#endif //DATIO_H