#include <npsio.h> 

void NPSIO::load(std::string& fn) {
	if (fn.substr(fn.length() - 3, 3) == "nps") {
		std::ifstream file;
		file.open(fn, std::ios::binary|std::ifstream::in);
		if (file.peek() == std::ifstream::traits_type::eof()) {
			file.close();
			return;
		}
		size_t length, size;
		while (1) {
			file.read(reinterpret_cast<char*>(&length), sizeof(size_t));
			if (file.eof())
				break;
			Para para;
			file.read(reinterpret_cast<char*>(&para), sizeof(Para));
			char* filename = new char[length];
			file.read(filename, length);
			file.read(reinterpret_cast<char*>(&size), sizeof(size_t));
			filelist.push_back(fn.substr(0, fn.find_last_of("/") + 1) + std::string(filename, length));
			paralist.push_back(para);
			n++;
			Peak* buffer = new Peak[size];
			file.read(reinterpret_cast<char*>(buffer), size * sizeof(Peak));
			for (int i = 0; i < size; i++)
				siglist.push_back(buffer[i]);
			mymap[filelist.back()] = std::pair<int, int>(siglist.size() - size, siglist.size());
			delete[] filename;
			delete[] buffer;
		}
		file.close();
	}
	return;
}

void NPSIO::save(std::string& fn) {
	if (fn.substr(fn.length() - 3, 3) != "nps")
		return;
	std::ofstream file;
	file.open(fn, std::ios::trunc | std::ios::binary);
	file.close();
	file.open(fn, std::ios::app | std::ios::binary);
	for (int i = 0; i < n; i++) {
		std::string filename(filelist[i].substr(fn.find_last_of("/")+1));
		size_t size = filename.size();
		file.write(reinterpret_cast<char*>(&size), sizeof(size_t));
		file.write(reinterpret_cast<char*>(&paralist[i]), sizeof(Para));
		file.write(filename.c_str(), size);
		size = mymap[filelist[i]].second - mymap[filelist[i]].first;
		file.write(reinterpret_cast<char*>(&size), sizeof(size_t));
		file.write(reinterpret_cast<char*>(&siglist[mymap[filelist[i]].first]), size * sizeof(Peak));
	}
	file.close();
}

void NPSIO::push(std::string& fn, Para& para, Peak* peak, int size) {
	if (mymap.find(fn) != mymap.end()) 
		remove(fn);
	filelist.push_back(fn);
	paralist.push_back(para);
	for (int i = 0; i < size; i++)
		siglist.push_back(peak[i]);
	mymap[filelist.back()] = std::pair<int, int>(siglist.size() - size, siglist.size());
	n++;
}

void NPSIO::remove(std::string& fn) {
	size_t start, end;
	if (mymap.find(fn) != mymap.end()) {
		for (int i = filelist.size() - 1; i >= 0; i--) {
			if (filelist[i] == fn) {
				filelist.erase(filelist.begin() + i, filelist.begin() + i + 1);
				paralist.erase(paralist.begin() + i, paralist.begin() + i + 1);
				start = mymap[fn].first;
				end = mymap[fn].second;
				siglist.erase(siglist.begin() + start, siglist.begin() + end);
				mymap.erase(fn);
				for (int j = i; j < filelist.size(); j++) {
					mymap[filelist[j]].first -= (end - start);
					mymap[filelist[j]].second -= (end - start);
				}
				n--;
				return;
			}
		}
	}
	return;
}