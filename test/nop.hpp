#include <iostream>
#include <iomanip>
#ifndef NOP_H
#define NOP_H

using namespace  std;

class Nop{
    private:
        int x;
        int y;
    public:
        Nop(){}
        void print(){};
        int get_x(){};
        int get_y(){};     
};
#endif