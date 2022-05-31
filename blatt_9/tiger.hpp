#ifndef TIGER_H
#define TIGER_H
#include "fleischfresser.hpp"
#include "saugetier.hpp"

class Tiger: public Fleischfresser, public Saeugetier{
    private:
        int alter;
    public:
        Tiger(int a,string n): alter(a) {
            set_name(n);
        }

        friend ostream& operator<< (ostream& stream, Tiger& ti){
            stream << "Klasse: Tiger" << endl;
            stream << "Name: " << ti.name << endl; 
            stream << "Alter: " << ti.alter <<  endl;
            stream << "Anzahl Zaehne: " << ti.zaehne <<  endl;
            stream << "Lebenserwartung: " << ti.lebenserwartung <<  endl;
            stream << "------------------------------------------------" << endl;
            stream << endl;

            return stream;
        }
};
#endif