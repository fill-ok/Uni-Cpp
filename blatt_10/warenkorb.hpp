#ifndef WARENKORB_H
#define WARENKORB_H
#include "obsthaendler.hpp"
#include <cstring>

class Warenkorb{
    private:
        string name;
        int counter;
        Artikel* warenkorb;
    public:
    // construcktor
        Warenkorb(string n): name(n), counter(0), warenkorb(new Artikel[counter]) {
            cout << "Neuen Warenkorb angelegt:" << endl;
            cout << "Warenkorb ist leer..." << endl;
        }
    // methods
        void add(Artikel& a){
            counter++;
			Artikel* tmp_arr = new Artikel[counter];
            memcpy(tmp_arr, warenkorb, sizeof(Artikel)*counter);

            delete []warenkorb;
            warenkorb = tmp_arr;
            
            warenkorb[counter-1] = a;
        }
        double get_Preis_warenkorb(){
            double gesamt_preis{};
            Artikel* tmp;
            for(int i=0;i<counter;i++){
                (*tmp) = warenkorb[i];

                if(tmp->get_herkunft() == "Brasilien"){
                    if((int)tmp->get_menge() % 2 == 0){
                        gesamt_preis += tmp->get_Preis() * (tmp->get_menge()/2);
                    } else{
                        gesamt_preis += tmp->get_Preis() * (tmp->get_menge()/2);
                        gesamt_preis += tmp->get_Preis() * 1;
                    }
                } else {
                    gesamt_preis += tmp->get_Preis() * tmp->get_menge();
                }

            } 
            delete []tmp;
            return gesamt_preis;
        }

        void get_info_warenkorb(){
            Artikel* tmp;
            for(int i=0;i<counter;i++){
                (*tmp) = warenkorb[i];
                tmp->info();
            }
            delete []tmp;
        }
};
#endif