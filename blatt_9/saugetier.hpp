#ifndef SAUGETIER_H
#define SAUGETIER_H 
#include "tier.hpp"

class Saeugetier: public virtual Tier{
    protected:
        int lebenserwartung;
    public:
        Saeugetier(){}
        Saeugetier(int leb): lebenserwartung(leb) {}

        friend ostream& operator<< (ostream& stream, Saeugetier& s){
            stream << "Klasse: Saeugetier" << endl;
            stream << "Name: " << s.name << endl; 
            stream << "Lebenserwartung: " << s.lebenserwartung <<  endl;
            stream << "------------------------------------------------" << endl;
            stream << endl;

            return stream;
        }
        
};

#endif


