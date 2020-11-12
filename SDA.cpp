#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include "SDA.h"

std::vector<int> SDA::distribute(std::vector<int> objects, int to_count) {
	using namespace std;
	while (objects.size() % to_count != 0) {
		objects.push_back(0);
	}
	std::sort(objects.begin(), objects.end());
	results.resize(to_count);
	while (entry < objects.size()) {
		for (i = entry; i < entry + to_count; i++) {
			tempvec.push_back(objects[i]);
		}
		if (rotate == 1) {
			std::sort(tempvec.begin(), tempvec.end(), std::greater<int>());
		}
		else {
			rotate = 1;
			std::sort(objects.begin(), objects.end());
		}
		for (i = 0; i < to_count; i++) {
			results[i] = results[i] + tempvec[i];
		}
		tempvec.clear();
		entry = entry + to_count;
	}
	return results;
}
