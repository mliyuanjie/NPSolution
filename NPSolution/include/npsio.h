#ifndef NPSIO_H
#define NPSIO_H 

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream> 
#include <fstream>
#include <ostream>
#include "tools.h"

class NPSIO {
public:
	void load(std::string&);
	void save(std::string&);
	void push(std::string&, Para&, Peak*, int);
	void remove(std::string&);


	std::vector<std::string> filelist;
	std::vector<Peak> siglist;
	std::vector<Para> paralist;
	std::unordered_map<std::string, std::pair<int, int>> mymap;
	int n = 0;	
};
#endif //NPSIO_H
