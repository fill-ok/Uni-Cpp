#ifndef PUNKT_H
#define PUNKT_H
#include <iostream>
#include <cmath>

using namespace std;

// Ein Punkt in der Ebene
class Punkt {
	private:
		int x;
		int y;
        static int anz_obj;
	public:  
		// Konstruktor
		Punkt(int xx=0, int yy=0) : x(xx), y(yy) {
            anz_obj++;
        }

		// Get- & Set-Methoden
		int get_x() const { return x; }
		int get_y() const { return y; }
		void set_x(int xx) { x = xx; }
		void set_y(int yy) { y = yy; }

		// Abstand zum Ursprung
		double betrag() const {
			return sqrt(x*y);
		}
        // ojb counter
        static void print_ojb_counter(){
            cout << "------------------------------------" << endl;
            cout << "--Anzahl ojb-- : " << Punkt::anz_obj << endl;
            cout << "------------------------------------" << endl;
        }

	// Ausgabeoperator
	friend std::ostream& operator<<(std::ostream& os, const Punkt& p) {
		os << "(" << p.x << "," << p.y << ")";
		return os;
	}

	// Eingabeoperator
	friend std::istream& operator>>(std::istream& is, Punkt& p) {
		is >> p.x >> p.y;
		return is;
	}
};
int Punkt::anz_obj = 0;
// Berechnet neuen Punkt als Differenz von zwei Punkten
Punkt operator-(const Punkt& p1, const Punkt& p2) {
	Punkt erg;
	erg.set_x(p1.get_x() - p2.get_x());
	erg.set_y(p1.get_y() - p2.get_y());
	return erg;
}
#endif