#pragma once
class SDA
{
public:
	std::vector<int> distribute(std::vector<int> objects, int to_count);
private:
	std::vector<int> results;
	std::vector<int> tempvec;
	int i, rotate, entry = 0;
};

