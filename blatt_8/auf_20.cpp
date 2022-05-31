#include <iostream>

template <typename T> class Polar{
    private:
        T rad;
        T phi;
    public:
        // constructors
            Polar(T r, T p) {
                rad = r;
                phi = p;
            }
            Polar(){}
        // methods
            T get_rad(){ return rad; }
            T get_phi(){return phi; }

        // operators
            friend std::ostream& operator << (std::ostream& stream, Polar& p){
                stream << "(" << p.rad << "," << p.phi << ")" <<std::endl;
                stream << "-------------------------" << std::endl;
                return stream;
            }
            friend Polar<T>& operator *= (Polar<T>& p1, Polar<T>& p2){
                p1.rad *= p2.rad;
                p1.phi *= p2.phi;

                return p1;
            }
            friend void operator * (Polar& p1, Polar& p2){
                Polar<T> p;
                p.rad = p1.get_rad() * p2.get_rad();
                p.phi = p1.get_phi() * p2.get_phi();
                
                std::cout << p;
            }
};

int main(){
    Polar <int> p1(4,6);
    Polar <int> p2(5,7);

    Polar <double> p3(4.0,6.0);
    Polar <double> p4(5.0,6.3);

    Polar <double> p_double;


    std::cout << p1;
    p4 *= p3;
    std::cout << p1;
}