#ifndef TIER_H
#define TIER_H
#include <iostream>

using namespace std;

class Tier{
    protected:
        string name;        
    public:
        Tier(){}
        Tier(string n): name(n) {}

        void set_name(string n){
            name = n;
        }

        friend ostream& operator<< (ostream& stream, Tier& t){
            stream << "Klasse: Tier" << endl;
            stream << "Name: " << t.name << endl; 
            stream << "------------------------------------------------" << endl;
            stream << endl;

            return stream;
        }
};

#endif