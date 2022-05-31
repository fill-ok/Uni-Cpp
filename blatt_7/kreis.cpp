#include <iostream>

using namespace std;

class Kreis{
    private:
        int x;
        int y;
        double rad;
    public:
    // constructor
        Kreis(): x(0), y(0), rad(0) {}

        Kreis(int x_enter, int y_enter, double rad_enter){
            x = x_enter;
            y = y_enter;
            rad = rad_enter;
        }

        
    // methods
        int get_x(){ return x; }
        int get_y(){ return y; }
        double get_rad(){ return rad; }

        void set_x(int &x_enter){
            x = x_enter;
        }

        void set_y(int &y_enter){
            y = y_enter;
        }

        void set_rad(int &rad_enter){
            rad = rad_enter;
        }

        void print(){
            cout << "x: " << x << " y: " << y << " rad: " << rad << endl;
        }
    // operator 
        friend istream& operator >> (istream& stream, Kreis& k){
            cout << "enter x: ";
            stream >> k.x;

            cout << "enter y: ";
            stream >> k.y;

            cout << "enter rad: ";
            stream >> k.rad;
        }    
          


};

Kreis operator + (Kreis& k1, Kreis& k2)  {
    Kreis k3;

    int x_tmp = k1.get_x() + k2.get_x();
    int y_tmp = k1.get_y() + k2.get_y();
    int rad_tmp = k1.get_rad() + k2.get_rad();

    k3.set_x(x_tmp);
    k3.set_y(y_tmp);
    k3.set_rad(rad_tmp);
    
    return k3;    
}

Kreis& operator += (Kreis& k1, Kreis& k2){
    k1 = k1 + k2;
    return k1;
}

int main(){
    Kreis k0;
    Kreis k(2,4,6.0);
    Kreis kk(2,4,6.0);
    
    k += kk;
    k.print();

}