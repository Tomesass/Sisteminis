#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Header.h"

using namespace std;
//using namespace N;


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
		double vid = 0;
		double mediana = 0;
		double sum = 0;
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
				vid = (double)sum / 6;
				galutinis = (double)(0.4 * vid) + (0.6 * egz);
				mediana = (double)(mas[2] + mas[3]) / 2;

				cout << setw(5) << vardas << "  " << setw(5) << pavarde << "   " << setprecision(3) << setw(10) << galutinis << "   " << setprecision(3) << setw(13) << (double)mediana << endl;

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

		try {
			cout << "Iveskite egzamino pazymi" << endl;
			cin >> egzPaz;
			if (egzPaz > 10 || egzPaz < 1) {
				throw 4;
			}
			vid = sum / pazymiai.size();
			try {
				cout << "Pasirinkite vidurki ar mediana\n";
				cout << "vidurkis - 1\n";
				cout << "mediana - 2\n";
				cin >> pasirinkimas;
				if (pasirinkimas > 2 || pasirinkimas < 1) {
					throw 7;
				}
			}
			catch (int error7) {
				cout << "Pasirinkimas netinkamas 1-2 !\n";
			}
			if (pasirinkimas == 1) {
				galutinis = (0.4 * vid) + (0.6 + egzPaz);
				cout << "Vardas  |  Pavarde  |   Galutinis (Vid.)" << endl;
				cout << "------------------------------------" << endl;
				cout << setw(5) << vardas << " | " << setw(5) << pavarde << " | " << setw(5) << galutinis << setprecision(3);
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
			cout << "iveskite namu darbu pazymius, 0 - issaugoti pakeitimus\n";
			while (n != 0) {
				cin >> n;
				if (n > 10) {
					throw 3;
				}
				pazymiai.push_back(n);
				sum += n;
			}

			pazymiai.pop_back();

			sort(pazymiai.begin(), pazymiai.end());

			try {

				cout << " iveskite egzamino pazymi" << endl;
				cin >> egzPaz;
				vid = sum / pazymiai.size();

				if (egzPaz > 10 || egzPaz < 1) {
					throw 5;
				}
			}catch (int error5) {
				cout << "Pazymys turi buti 10 baleje sistemoje !\n";
					}
				cout << " pasirinkite vidurki ar mediana\n";
				cout << "vidurkis - 1\n";
				cout << "mediana - 2\n";

			try {
				cin >> pasirinkimas;
				if (pasirinkimas < 1 || pasirinkimas > 2) {
					throw 4;
				}
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
					cout <<setw(5) << vardas << " | " <<setw(5) << pavarde << " | " <<setw(13) << (double)mediana << setprecision(3);

				}
			}
			catch (int error4) {
				cout << "Pasirinkimas turi buti 1-2 !\n";
			}

		}
		catch (int error3) {
			cout << "Pazymiai turi buti 10 baleje sistemoje!\n";
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

				try {
					cout << "Iveskite egzamino pazymi" << endl;
					cin >> egzPaz;
					vid = sum / 4;
					if (egzPaz > 10 || egzPaz < 1) {
						throw 6;
					}
				}
				catch (int error6) {
					cout << "Pazymys turi buti 10 baleje sistemoje !\n";
				}

				try {
					cout << " pasirinkite vidurki ar mediana\n";
					cout << "vidurkis - 1\n";
					cout << "mediana - 2\n";
					cin >> pasirinkimas;
					if (pasirinkimas > 2 || pasirinkimas < 1) {
						throw 7;
					}
				}
				catch (int error7) {
					cout << "Pasirinkimas netinkamas 1-2 !\n";
				}

				if (pasirinkimas == 1) {
					galutinis = (0.4 * vid) + (0.6 + egzPaz);
					cout << "Vardas  |  Pavarde  |   Galutinis (Vid.)" << endl;
					cout << "------------------------------------" << endl;
					cout << setw(5) << vardas << " | " << setw(5) << pavarde << " | " << setw(13) << galutinis << setprecision(3);
				}
				else if (pasirinkimas == 2) {
					ndRez.pop_back();
					ndRez.pop_front();
					mediana = (ndRez.front() + ndRez.back()) / 2;
					cout << "Vardas  |  Pavarde  |   Galutinis (Med.)" << endl;
					cout << "------------------------------------" << endl;
					cout << setw(5) << vardas << " | " << setw(5) << pavarde << " | " << setw(13) << (double)mediana << setprecision(3);
				}
				
			}catch (int error2) {
				cout << "Pazymiai turi buti 10 baleje sistemoje!\n";
			
			}
		}
	};

class failasGeneruoti1 {
public:
	failasGeneruoti1() {

		int x = 1;
		int nd1;
		int nd2;
		int nd3;
		int nd4;
		int nd5;
		double egz;
		double galutinis = 0;
		double vid = 0;
		double sum = 0;


		ofstream sar1("Sarasas1.txt");
		ofstream sar11("Vargsiukai1.txt");
		ofstream sar12("Galvociai1.txt");

		sar1 << "Vardas " << "  Pavarde" << "  nd1" << "  nd2" << "  nd3" << "  nd4" << "  nd5" << " egz\n";
		sar1 << "----------------------------------------------------------------------------------------\n";
		for (int i = 0; i < 1000; i++) {
			nd1 = rand() % 10 + 1;
			nd2 = rand() % 10 + 1;
			nd3 = rand() % 10 + 1;
			nd4 = rand() % 10 + 1;
			nd5 = rand() % 10 + 1;
			egz = rand() % 10 + 1;
			sum = nd1 + nd2 + nd3 + nd4 + nd5;
			vid =(double) sum / 5;
			galutinis =(double) (0.4 * vid) + (0.6 * egz);

			sar1 << "Vardas" << x << "  " << "Pavarde" << x << "  " << nd1 << "  " << nd2 << "  " << nd3 << "  " << nd4 << "  " << nd5 << "  " << egz <<"  Galutinis: "<<galutinis << endl;

			if (galutinis < 5) {

				sar11 << "Vardas" << x << "  " << "Pavarde" << x << "  " << nd1 << "  " << nd2 << "  " << nd3 << "  " << nd4 << "  " << nd5 << "  " << egz << "  Galutinis: " << galutinis << endl;
			}
			else if (galutinis >= 5) {

				sar12 << "Vardas" << x << "  " << "Pavarde" << x << "  " << nd1 << "  " << nd2 << "  " << nd3 << "  " << nd4 << "  " << nd5 << "  " << egz << "  Galutinis: " << galutinis << endl;
				
			}
			x++;
		}

		sar11.close();
		sar12.close();
		sar1.close();


		}
};

class failasGeneruoti2 {
public:
	failasGeneruoti2() {

		int x = 1;
		int nd1;
		int nd2;
		int nd3;
		int nd4;
		int nd5;
		double egz;
		double galutinis = 0;
		double vid = 0;
		double sum = 0;


		ofstream sar2("Sarasas2.txt");
		ofstream sar21("Vargsiukai2.txt");
		ofstream sar22("Galvociai2.txt");

		sar2 << "Vardas " << "  Pavarde" << "  nd1" << "  nd2" << "  nd3" << "  nd4" << "  nd5" << " egz\n";
		sar2 << "----------------------------------------------------------------------------------------\n";

		for (int i = 0; i < 10000; i++) {
			nd1 = rand() % 10 + 1;
			nd2 = rand() % 10 + 1;
			nd3 = rand() % 10 + 1;
			nd4 = rand() % 10 + 1;
			nd5 = rand() % 10 + 1;
			egz = rand() % 10 + 1;
			sum = nd1 + nd2 + nd3 + nd4 + nd5;
			vid = (double)sum / 5;
			galutinis = (double)(0.4 * vid) + (0.6 * egz);

			sar2 << "Vardas" << x << "  " << "Pavarde" << x << "  " << nd1 << "  " << nd2 << "  " << nd3 << "  " << nd4 << "  " << nd5 << "  " << egz << endl;

			if (galutinis < 5) {

				sar21 << "Vardas" << x << "  " << "Pavarde" << x << "  " << nd1 << "  " << nd2 << "  " << nd3 << "  " << nd4 << "  " << nd5 << "  " << egz << "  Galutinis: " << galutinis << endl;
			}
			else if (galutinis >= 5) {

				sar22 << "Vardas" << x << "  " << "Pavarde" << x << "  " << nd1 << "  " << nd2 << "  " << nd3 << "  " << nd4 << "  " << nd5 << "  " << egz << "  Galutinis: " << galutinis << endl;
			}
			x++;
		}
			sar2.close();
			sar21.close();
			sar22.close();
	}
};

class failasGeneruoti3 {
public:
	failasGeneruoti3() {

		int x = 1;
		int nd1;
		int nd2;
		int nd3;
		int nd4;
		int nd5;
		double egz;
		double galutinis = 0;
		double vid = 0;
		double sum = 0;


		ofstream sar3("Sarasas3.txt");
		ofstream sar31("Vargsiukai3.txt");
		ofstream sar32("Galvociai3.txt");

		sar3 << "Vardas " << "  Pavarde" << "  nd1" << "  nd2" << "  nd3" << "  nd4" << "  nd5" << " egz\n";
		sar3 << "----------------------------------------------------------------------------------------\n";

		for (int i = 0; i < 100000; i++) {
			nd1 = rand() % 10 + 1;
			nd2 = rand() % 10 + 1;
			nd3 = rand() % 10 + 1;
			nd4 = rand() % 10 + 1;
			nd5 = rand() % 10 + 1;
			egz = rand() % 10 + 1;
			sum = nd1 + nd2 + nd3 + nd4 + nd5;
			vid = (double)sum / 5;
			galutinis = (double)(0.4 * vid) + (0.6 * egz);

			sar3 << "Vardas" << x << "  " << "Pavarde" << x << "  " << nd1 << "  " << nd2 << "  " << nd3 << "  " << nd4 << "  " << nd5 << "  " << egz << endl;

			if (galutinis < 5) {

				sar31 << "Vardas" << x << "  " << "Pavarde" << x << "  " << nd1 << "  " << nd2 << "  " << nd3 << "  " << nd4 << "  " << nd5 << "  " << egz << "  Galutinis: " << galutinis << endl;
			}
			else if (galutinis >= 5) {

				sar32 << "Vardas" << x << "  " << "Pavarde" << x << "  " << nd1 << "  " << nd2 << "  " << nd3 << "  " << nd4 << "  " << nd5 << "  " << egz << "  Galutinis: " << galutinis << endl;
			}

			x++;
		}
		sar3.close();
		sar31.close();
		sar32.close();
	}
};

class failasGeneruoti4 {
public:
	failasGeneruoti4() {

		int x = 1;
		int nd1;
		int nd2;
		int nd3;
		int nd4;
		int nd5;
		double egz;
		double galutinis = 0;
		double vid = 0;
		double sum = 0;


		ofstream sar4("Sarasas4.txt");
		ofstream sar41("Vargsiukai4.txt");
		ofstream sar42("Galvociai4.txt");

		sar4 << "Vardas " << "  Pavarde" << "  nd1" << "  nd2" << "  nd3" << "  nd4" << "  nd5" << " egz\n";
		sar4 << "----------------------------------------------------------------------------------------\n";

		for (int i = 0; i < 1000000; i++) {
			nd1 = rand() % 10 + 1;
			nd2 = rand() % 10 + 1;
			nd3 = rand() % 10 + 1;
			nd4 = rand() % 10 + 1;
			nd5 = rand() % 10 + 1;
			egz = rand() % 10 + 1;
			sum = nd1 + nd2 + nd3 + nd4 + nd5;
			vid = (double)sum / 5;
			galutinis = (double)(0.4 * vid) + (0.6 * egz);

			sar4 << "Vardas" << x << "  " << "Pavarde" << x << "  " << nd1 << "  " << nd2 << "  " << nd3 << "  " << nd4 << "  " << nd5 << "  " << egz << endl;

			if (galutinis < 5) {

				sar41 << "Vardas" << x << "  " << "Pavarde" << x << "  " << nd1 << "  " << nd2 << "  " << nd3 << "  " << nd4 << "  " << nd5 << "  " << egz << "  Galutinis: " << galutinis << endl;
			}
			else if (galutinis >= 5) {

				sar42 << "Vardas" << x << "  " << "Pavarde" << x << "  " << nd1 << "  " << nd2 << "  " << nd3 << "  " << nd4 << "  " << nd5 << "  " << egz << "  Galutinis: " << galutinis << endl;
			}

			x++;
		}
		sar4.close();
		sar41.close();
		sar42.close();
	}
};

class failasGeneruoti5 {
public:
	failasGeneruoti5() {

		int x = 1;
		int nd1;
		int nd2;
		int nd3;
		int nd4;
		int nd5;
		double egz;
		double galutinis = 0;
		double vid = 0;
		double sum = 0;


		ofstream sar5("Sarasas5.txt");
		ofstream sar51("Vargsiukai5.txt");
		ofstream sar52("Galvociai5.txt");

		sar5 << "Vardas " << "  Pavarde" << "  nd1" << "  nd2" << "  nd3" << "  nd4" << "  nd5" << " egz\n";
		sar5 << "----------------------------------------------------------------------------------------\n";


		for (int i = 0; i < 10000000; i++) {
			nd1 = rand() % 10 + 1;
			nd2 = rand() % 10 + 1;
			nd3 = rand() % 10 + 1;
			nd4 = rand() % 10 + 1;
			nd5 = rand() % 10 + 1;
			egz = rand() % 10 + 1;
			sum = nd1 + nd2 + nd3 + nd4 + nd5;
			vid = (double)sum / 5;
			galutinis = (double)(0.4 * vid) + (0.6 * egz);

			sar5 << "Vardas" << x << "  " << "Pavarde" << x << "  " << nd1 << "  " << nd2 << "  " << nd3 << "  " << nd4 << "  " << nd5 << "  " << egz << endl;
	
			if (galutinis < 5) {

				sar51 << "Vardas" << x << "  " << "Pavarde" << x << "  " << nd1 << "  " << nd2 << "  " << nd3 << "  " << nd4 << "  " << nd5 << "  " << egz << "  Galutinis: " << galutinis << endl;
			}
			else if (galutinis >= 5) {

				sar52 << "Vardas" << x << "  " << "Pavarde" << x << "  " << nd1 << "  " << nd2 << "  " << nd3 << "  " << nd4 << "  " << nd5 << "  " << egz << "  Galutinis: " << galutinis << endl;
			}
			
			x++;
		}
		sar5.close();
		sar51.close();
		sar52.close();
	}
};

	int main() {

	//	ndFailas file;
	//	ndFailas();

		int pasirinkimas;
		try {
			cout << "1 - Namu darbu kiekis nezinomas\n";
			cout << "2 - Namu darbu kiekis zinomas(4)\n";
			cout << "3 - Namu darbai generuojami atsitiktinai\n";
			cout << "4 - Skaitymas is failo\n";
			cout << "5 - Sarasu generavimas ir skirstymas (Vargsiukai/Galvociai)\n";

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
			else if (pasirinkimas == 5) {
				try {
					int x;
					cout << "Kelinta sarasa norite generuoti ir surusiuoti?  1-5\n";
					cin >> x;
					if (x > 5 || x < 1) {
						throw 10;
					}
					if (x == 1) {
						failasGeneruoti1 obj;
					}
					else if (x == 2) {
						failasGeneruoti2 obj2;
					}
					else if (x == 3) {
						failasGeneruoti3 obj3;
					}
					else if (x == 4) {
						failasGeneruoti4 obj4;
					}
					else if (x == 5) {
						failasGeneruoti5 obj5;
					}
				}
				catch (int error10) {
					cout << "Blogai pasirinktas sarasas 1-5 !\n";
				}
			}
			if (pasirinkimas > 5) {
				throw 1; }
		}
		catch (int error) {
			cout << "Netinkamas pasirinkimas!\n";
		}



		return 0;
	}