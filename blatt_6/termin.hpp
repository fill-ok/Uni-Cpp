#ifndef TERMIN_H
#define TERMIN_H
#include "datum.hpp"
#include "zeit.hpp"
#include <iomanip>
#include <iostream>

class Termin{
    private:
        Zeit time;
        unsigned int duration;
        string description;
    public:

    //constructors    
    Termin(string description_enter, unsigned int duration_enter, Zeit& time_enter){
        this-> description = description_enter;
        this-> duration = duration_enter;
        this-> time = time_enter;
    }

    void print_appointment(){
        cout << "Termin: " << description << endl;
        cout << "Beginn: "; time.print_date_time();
        cout << "Ende: "; time.Zeit::operator+=(duration); time.print_date_time();
    }
};
#endif