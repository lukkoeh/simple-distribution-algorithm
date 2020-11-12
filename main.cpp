#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

#include "SDA.h"

int main(int argc, char* argv[]) {
	using namespace std;

	//sample data
	vector<int> values{ 1,2,3 };
	int distrib_to = 2;

	SDA sda;
	vector<int> result = sda.distribute(values, distrib_to);

	for (int x : result) {
		cout << x << endl;
	}
	
}