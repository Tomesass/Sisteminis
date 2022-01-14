#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void showlist(list <int> g) {
	list <int> ::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		cout << '\t' << *it;
	cout << '\n';
}


class ndRandom {
public:
	ndRandom() {
		string vardas;
		string pavarde;
		double galutinis;
		double vid;
		int egzPaz;
		int sum = 0;
		int pasirinkimas;
		double mediana;
		int n = 1;
		int paz;
		list <int> ndRez;
		int random;
		int kiek;

		cout << "Iveskite varda pavarde\n";
		cin >> vardas >> pavarde;

		vector<int> pazymiai;
		
		
		cout << "Kiek yra pazymiu?\n";
		cin >> kiek;

		for (int i=0; i <= kiek; i++) {
			random = rand() % 10 + 1;
			pazymiai.push_back(random);
			sum += random;
		}
		pazymiai.pop_back();

		sort(pazymiai.begin(), pazymiai.end());
		for (auto x : pazymiai);

		for (const int& i : pazymiai) {
			cout << i << " ";
		}

		cout << " iveskite egzamino pazymi" << endl;
		cin >> egzPaz;
		vid = sum / pazymiai.size();

		cout << " pasirinkite vidurki ar mediana\n";
		cout << "vidurkis - 1\n";
		cout << "mediana - 2\n";
		cin >> pasirinkimas;

		if (pasirinkimas == 1) {
			galutinis = (0.4 * vid) + (0.6 + egzPaz);
			cout << "Vardas  |  Pavarde  |   Galutinis (Vid.)" << endl;
			cout << "------------------------------------" << endl;
			cout << vardas << " | " << pavarde << " | " << galutinis << setprecision(3);
		}
		else if (pasirinkimas == 2) {
			if (pazymiai.size() % 2 == 0) {
				int i = pazymiai.size() / 2 - 1;
				int n = i + 1;
				mediana = (double)(pazymiai[i] + pazymiai[n]) / 2;
			}
			else if (pazymiai.size() % 2 != 0) {
				int i = pazymiai.size() / 2;
				mediana = (double)pazymiai[i];
			}
			cout << "Vardas  |  Pavarde  |   Galutinis (Med.)" << endl;
			cout << "------------------------------------" << endl;
			cout << vardas << " | " << pavarde << " | " << (double)mediana << setprecision(3);

		}
		else (cout << "Pasirinkimas netinka");

	}
};


class ndNezinomi {
public:
	ndNezinomi() {
		string vardas;
		string pavarde;
		double galutinis;
		double vid;
		int egzPaz;
		int sum = 0;
		int pasirinkimas;
		double mediana;
		int n = 1;
		int paz;
		list <int> ndRez;

		cout << "Iveskite varda pavarde\n";
		cin >> vardas >> pavarde;

		vector<int> pazymiai;
		cout << "iveskite namu darbu pazymius\n";
		while (n != 0) {
			cin >> n;
			pazymiai.push_back(n);
			sum += n;
		}
		pazymiai.pop_back();

		sort(pazymiai.begin(), pazymiai.end());
		for (auto x : pazymiai);

		for (const int& i : pazymiai) {
			cout << i << " ";

		}
		cout <<pazymiai.size();

		cout << " iveskite egzamino pazymi" << endl;
		cin >> egzPaz;
		vid = sum / pazymiai.size();

		cout << " pasirinkite vidurki ar mediana\n";
		cout << "vidurkis - 1\n";
		cout << "mediana - 2\n";
		cin >> pasirinkimas;

		if (pasirinkimas == 1) {
			galutinis = (0.4 * vid) + (0.6 + egzPaz);
			cout << "Vardas  |  Pavarde  |   Galutinis (Vid.)" << endl;
			cout << "------------------------------------" << endl;
			cout << vardas << " | " << pavarde << " | " << galutinis << setprecision(3);
		}
		else if (pasirinkimas == 2) { 
			if (pazymiai.size() % 2 == 0) {
				int i = pazymiai.size() / 2 - 1;
				int n = i + 1;
				mediana =(double) (pazymiai[i] + pazymiai[n]) / 2;
			}
			else if (pazymiai.size() % 2 != 0) {
				int i = pazymiai.size() / 2 ;
				mediana = (double) pazymiai[i];
			}
			cout << "Vardas  |  Pavarde  |   Galutinis (Med.)" << endl;
			cout << "------------------------------------" << endl;
			cout << vardas << " | " << pavarde << " | " << (double)mediana << setprecision(3);
			
		}
		else (cout << "Pasirinkimas netinka");
	}
	};




	class ndZinomi {
	public:
		ndZinomi() {
			string vardas;
			string pavarde;
			double galutinis;
			double vid;
			int egzPaz;
			int sum = 0;
			int pasirinkimas;
			double mediana;
			int n = 1;
			int paz;
			list <int> ndRez;

			cout << "iveskite varda, pavarde" << endl;
			cin >> vardas >> pavarde;
			cout << "iveskite keturis namu darbu pazymius: " << endl;

			for (int i = 1; i <= 4; i++) {
				cin >> paz;
				ndRez.push_back(paz);
				ndRez.sort();
				sum += paz;
			}

			showlist(ndRez);

			cout << " iveskite egzamino pazymi" << endl;
			cin >> egzPaz;
			vid = sum / 4;

			cout << " pasirinkite vidurki ar mediana\n";
			cout << "vidurkis - 1\n";
			cout << "mediana - 2\n";
			cin >> pasirinkimas;

			if (pasirinkimas == 1) {
				galutinis = (0.4 * vid) + (0.6 + egzPaz);
				cout << "Vardas  |  Pavarde  |   Galutinis (Vid.)" << endl;
				cout << "------------------------------------" << endl;
				cout << vardas << " | " << pavarde << " | " << galutinis << setprecision(3);
			}
			else if (pasirinkimas == 2) {
				ndRez.pop_back();
				ndRez.pop_front();
				mediana = (ndRez.front() + ndRez.back()) / 2;
				cout << "Vardas  |  Pavarde  |   Galutinis (Med.)" << endl;
				cout << "------------------------------------" << endl;
				cout << vardas << " | " << pavarde << " | " << (double)mediana << setprecision(3);
			}
			else (cout << "Pasirinkimas netinka");




		}


	};



	int main() {
		int pasirinkimas;

		cout << "1 - Namu darbu kiekis nezinomas\n";
		cout << "2 - Namu darbu kiekis zinomas(4)\n";
		cout << "3 - Namu darbai generuojami atsitiktinai\n";

		cin >> pasirinkimas;

		if (pasirinkimas == 1) {
			ndNezinomi obj;
		}
		else if (pasirinkimas == 2) {
			
			ndZinomi obj;
		}
		else if (pasirinkimas == 3) {
			ndRandom obj;
		}
		else cout << "Pasirinkimas netinkamas\n";




		return 0;
	}