#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
#include <iomanip>
using namespace std;

void showlist(list <int> g) {
	list <int> ::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		cout << '\t' << *it;
	cout << '\n';
}




class student {
public: 
		student() {
	string vardas;
	string pavarde;
	double galutinis; // galutinis = 0.4 * vidurkis + 0.6 * egzaminas
	double vid;
	int paz;
	int egzPaz;
	int sum=0;
	list <int> ndRez;

	cin >> vardas >> pavarde;
	cout << "iveskite keturis namu darbu pazymius: " << endl;

	for (int i=1; i <= 4; i++) {
		cin >> paz;
		ndRez.push_back(paz);
		sum += paz;
	}

	cout << " iveskite egzamino pazymi" << endl;
	cin >> egzPaz;
	vid = sum / 4;
	

	galutinis = (0.4 * vid) + (0.6 + egzPaz);

	cout << "Vardas  |  Pavarde  |   Galutinis(Vid.)" << endl;
	cout << "------------------------------------" << endl;
	cout << vardas << " | " << pavarde << " | " << galutinis << setprecision(3);

	}

	
};



int main() {

	cout << "iveskite varda, pavarde" << endl;
	student obj;


	return 0;
}