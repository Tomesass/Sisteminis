#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

void showlist(list <int> g) {
	list <int> ::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		cout << '\t' << *it;
	cout << '\n';
}


class ndFailas {
public:
	ndFailas() {
		string line;
		string vardas;
		string pavarde;
		double nd1;
		double nd2;
		double nd3;
		double nd4;
		double nd5;
		double egz;
		double vid=0;
		double mediana=0;
		double sum=0;
		double  galutinis;


		ifstream failas;
		failas.open("kursiokai.txt");
		if (failas.is_open()) {
			while (getline(failas, line)) {
				istringstream ss(line);
				ss >> vardas >> pavarde >> nd1 >> nd2 >> nd3 >> nd4 >> nd5 >> egz;
				double mas[] = { nd1, nd2, nd3, nd4, nd5, egz };
				int n = sizeof(mas) / sizeof(mas[0]);
				sort(mas, mas + n);

			sum = nd1 + nd2 + nd3 + nd4 + nd5 + egz;
			vid =(double) sum / 6;
			galutinis =(double) (0.4 * vid) + (0.6 * egz);
			mediana = (double) (mas[2] + mas[3]) / 2;

			cout <<setw(5) << vardas << "  " <<setw(5) << pavarde << "   " << setprecision(3) << setw(10) << galutinis << "   " << setprecision(3) << setw(13) << (double)mediana << endl;
		
			}
		}
		failas.close();


	}
};

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

		try {
			cout << " iveskite egzamino pazymi" << endl;
			cin >> egzPaz;
			if (egzPaz > 10 || egzPaz < 1) {
				throw 4;
			}
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
				cout << setw(5) << vardas << " | " << setw(5) << pavarde << " | " << setw(13) << (double)mediana << setprecision(3);

			}
		}
		catch (int error4) {
			cout << "Pazymys turi buti 10 baleje sistemoje!\n";
		}


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
		try {
			vector<int> pazymiai;
			cout << "iveskite namu darbu pazymius\n";
			while (n != 0) {
				cin >> n;
				if (n > 10 || n < 1) {
					throw 3;
				}
				pazymiai.push_back(n);
				sum += n;
			}

			pazymiai.pop_back();

			sort(pazymiai.begin(), pazymiai.end());
			for (auto x : pazymiai);

			for (const int& i : pazymiai) {
				cout << i << " ";

			}
			cout << pazymiai.size();


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

		}
		catch (int error3) {
			cout << "Pazymiai turi buti 10 baleje sistemoje!\n";
			//else (cout << "Pasirinkimas netinka");
		}
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
			try {
				for (int i = 1; i <= 4; i++) {
					cin >> paz;
					if (paz > 10 || paz < 1) {
						throw 2;
					}
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
				
			}catch (int error2) {
				cout << "Pazymiai turi buti 10 baleje sistemoje!\n";
			
			}
				


		}


	};




	int main() {
		int pasirinkimas;
		try {
			cout << "1 - Namu darbu kiekis nezinomas\n";
			cout << "2 - Namu darbu kiekis zinomas(4)\n";
			cout << "3 - Namu darbai generuojami atsitiktinai\n";
			cout << "4 - Skaitymas is failo\n";

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
			else if (pasirinkimas == 4) {

				cout << "Vardas   Pavarde     Galutinis(Vid.)    Galutinis(Med.)\n";
				cout << "-------------------------------------------------------\n";
				ndFailas obj;
			}

			if (pasirinkimas > 4) {
				throw 1; }
		}
		catch (int error) {
			cout << "Netinkamas pasirinkimas!\n";
		}



		return 0;
	}