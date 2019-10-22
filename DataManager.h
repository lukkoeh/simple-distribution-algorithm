#pragma once
#include "headers.h"
class DataManager
{
public:
	int getValueByIndex(int index);
	int verteilen();
private:
	std::vector<int> preisliste;
	std::vector<int> ergebnisse;
	std::vector<int> tempvec;
	int i, loop, personen, temp, rotate, eintrag = 0;
};

