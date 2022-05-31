#ifndef FLEISCHFRESSER_H
#define FLEISCHFRESSER_H
#include "tier.hpp"

class Fleischfresser: public virtual Tier{
    protected:
        int zaehne;
    public:
        Fleischfresser(){}
        Fleischfresser(int z): zaehne(z) {}

        friend ostream& operator<< (ostream& stream, Fleischfresser& f){
            stream << "Klasse: Fleischfresser" << endl;
            stream << "Name: " << f.name << endl; 
            stream << "Anzahl Zaehne: " << f.zaehne <<  endl;
            stream << "------------------------------------------------" << endl;
            stream << endl;

            return stream;
        }

};   
#endif