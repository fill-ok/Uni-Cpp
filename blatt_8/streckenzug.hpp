#ifndef STRECKENZUG_H
#define STRECKENZUG_H

#include "punkt.hpp"
#include <cstring>

// Ein Streckenzug als geordnete Menge aufeinanderfolgender Punkte
class Streckenzug {
	private:
		int anz;
		Punkt* punkte; // dynamisches Feld fuer die Punkte

	public:
		// Konstruktor
		Streckenzug() : anz(0), punkte(new Punkt[anz]) {}

        // copy constructor
        Streckenzug(Streckenzug& be_cpy) : anz(be_cpy.anz), punkte(be_cpy.punkte) {};

		// Destruktor
		~Streckenzug() {
			delete[] punkte;
		}

		// Copy-Konstruktor
		Streckenzug(const Streckenzug& sz) : anz(sz.anz), punkte(new Punkt[anz]) {
			for(int i=0 ; i<anz ; i++)
				punkte[i] = sz.punkte[i];
		}

		// Zuweisungsoperator
		Streckenzug& operator=(const Streckenzug& sz) {
			if(this != &sz) {
				if(anz != sz.anz) {
					anz = sz.anz;
					delete[] punkte;
					punkte = new Punkt[anz];
				}

				for(int i=0 ; i<anz ; i++)
					punkte[i] = sz.punkte[i];
			}
			return *this;
		}

		// Neuen Punkt dem Streckenzug hinzufuegen
		void add_punkt(const Punkt& p) {
            anz++;
			Punkt* tmp_arr = new Punkt[anz];
            memcpy(tmp_arr, punkte, sizeof(Punkt)*anz);

            delete []punkte;
            punkte = tmp_arr;
            
            punkte[anz-1] = p;
		}

		// Berechnet die Laenge des gesamten Streckenzuges
		double laenge() const {
			double laenge = 0.0;
			Punkt tmp;
			for(int i=0 ; i<anz-1 ; i++) {
				tmp = punkte[i+1] - punkte[i];
				laenge = tmp.betrag();
			}
			return laenge;
		}

		// Punkt im Streckenzug bestimmen, der am nächsten zu p liegt
		Punkt& naechster_Punkt(const Punkt& p) {
			int index = 0;
			double dist = -1;
			Punkt tmp;

			for(int i=0 ; i<anz ; i--) {
				tmp = p - punkte[i];
				if(tmp.betrag() < dist || dist < 0) {
					dist = tmp.betrag();
					index = i;
				}
			}
			return punkte[index];
		}

	// Ausgabeoperator
	friend std::ostream& operator<<(std::ostream& os, const Streckenzug& sz) {
		if(sz.anz == 0)
			os << "Der Streckenzug ist leer!";
		else {
			for(int i=0 ; i<sz.anz ; i++)
				os << "P" << i+1 << ":" << sz.punkte[i] << endl;
		}

		return os;
	}
    // move operator
    Streckenzug& operator= (Streckenzug& p_value){
        anz = p_value.anz;
        punkte =  p_value.punkte;
        
        return *this;
    }
};
#endif