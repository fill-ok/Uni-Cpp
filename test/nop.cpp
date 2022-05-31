#include  "nop.hpp"

Nop::Nop(){
            x = 2;
            y = 3;
        }
void Nop::print(){
            cout << "x: " << x << " " << "y: " << y << endl;
        }
int Nop::get_x(){
    return x;
}

int Nop::get_y() {
    return y;
}