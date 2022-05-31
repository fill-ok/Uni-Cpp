#ifndef MITGLIED_H
#define MITGLIED_Hss
#include <iostream>

using namespace  std;

class Mitglied {
    private:
        string name;
    public:
        // constructors
            Mitglied(string s="") : name{s} {};
        // methods
        // operators
        friend ostream& operator<< (ostream& stream, Mitglied& m){
            return stream << m.name << endl;
        }
        string get_name(){
            return name;
        }
};

#endif