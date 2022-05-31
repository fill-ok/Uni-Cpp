#include "streckenzug.hpp"


// Hauptprogramm
int main()  {
	Punkt::print_ojb_counter();

	Streckenzug p1;
	p1.add_punkt(Punkt(0,0));
	p1.add_punkt(Punkt(1,1));
	p1.add_punkt(Punkt(2,1));
	cout << "Streckenzug nach Definition von 3 Punkten: " << endl;
	cout << p1 << endl;
	cout << "Laenge: " << p1.laenge() << endl << endl;

	Streckenzug p2(p1);
	cout << "Streckenzug nach Definition von 3 Punkten: " << endl;
	cout << p2 << endl;
	cout << "Laenge: " << p2.laenge() << endl << endl;



	// p1.add_punkt(Punkt(0,0));
	// p1.add_punkt(Punkt(4,-2));
	// cout << "Streckenzug nach Definition von 5 Punkten: " << endl;
	// cout << p1 << endl;
	// cout << "Laenge: " << p1.laenge() << endl << endl;

	// {
	// 	cout << "Punkt eingeben: ";
	// 	Punkt t;
	// 	cin >> t;
	// 	cout << "Der Punkt " << t << " liegt am naechsten an Eckpunkt " << p1.naechster_Punkt(t) << endl << endl << endl;

	// 	// Aufgabenteil c)
	// }

	// Aufgabenteil d)
	/*
	 * cout << endl;
	 * cout << "Verwende Move-Konstruktor fuer p2: " << endl;
	 * Streckenzug p2(move(p1));
	 * cout << "Streckenzug p1 nach Move-Konstruktor: " << p1 << endl;
	 * cout << "Streckenzug p2: \n" << p2 << endl << endl;
	 *
	 * cout << "Verwende Move-Zuweisungsoperator fuer p1: " << endl;
	 * p1 = move(p2);
	 * cout << "Streckenzug p2 nach Move-Konstruktor: " << p2 << endl;
	 * cout << "Streckenzug p1: \n" << p1 << endl << endl;
	 */

	// Aufgabenteil c)
	//Punkt::printAnz();

	return 0;
}
