#include "headers.h"
#include "DataManager.h"

int DataManager::verteilen() {
	using namespace std;
	cout << "Wie viele Preise gibt es? " << endl;
	cin >> loop;
	for (i = 0; i < loop; i++) {
		cout << "Preis " + to_string(i + 1) + " als Ganzzahl an:  ";
		cin >> temp;
		preisliste.push_back(temp);
	}
	cout << "Auf wieviele Personen sollen diese Preise verteilt werden?";
	cin >> temp;
	personen = temp;
	while (preisliste.size() % personen != 0) {
		preisliste.push_back(0);
	}
	//std::sort(preisliste.begin(), preisliste.end(), std::greater<int>());
	std::sort(preisliste.begin(), preisliste.end());
	ergebnisse.resize(personen);
	while (eintrag < preisliste.size()) {
		for (i = eintrag; i < eintrag + personen; i++) {
			tempvec.push_back(preisliste[i]);
		}
		if (rotate == 1) {
			std::sort(tempvec.begin(), tempvec.end(), std::greater<int>());
		}
		else {
			rotate = 1;
			std::sort(preisliste.begin(), preisliste.end());
		}
		for (i = 0; i < personen; i++) {
			ergebnisse[i] = ergebnisse[i] + tempvec[i];
		}
		tempvec.clear();
		eintrag = eintrag + personen;
	}
	cout << "+++ Die Preise wurden verteilt +++" << endl;
	for (i = 0; i<ergebnisse.size(); i++) {
		cout << ergebnisse[i] << endl;
	}
	return 0;
}
