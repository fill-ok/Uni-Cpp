#include <iostream>
#include "datum.hpp"
#include "zeit.hpp"
#include "termin.hpp"

int main(){
    
    Datum d(29,6,2021);
    d += 184;
    d.print();
}
