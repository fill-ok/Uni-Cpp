#include <iostream>
#include <cmath>

using namespace std;
template <typename T, typename S> class Kreis {
   private:
    T m_x; //x-Koordinate Mittelpunkt
    T m_y; //y-Koordinate Mittelpunkt
    S rad; //Radius

  public:
    // constructors
        Kreis(T x, T y, S r) : m_x(x), m_y(y), rad(r) {
        if(rad<0) rad*=-1;    
        }
    // setter/ getter
        void setMittelpunkt(int x, int y) {
        m_x = x;
        m_y = y;
        }
	
        void setRad(double r) {
            rad = r;
        }
	
        int getX() const {return m_x;}
        int getY() const {return m_y;}
        double getRad() const {return rad;}
        
    // methods
        void berechne_flaecheninhalt(){
            cout << "Flaecheninahlt = " << pow(rad,2) << endl;
        }
        void berechne_umfang(){
            cout << "Umfang = " << 2*M_PI*(rad);
        }

        void ist_im_kreis(int x, int y){
            T m1 = m_x;
            T m2 = m_y;
            S radius{};
            radius = sqrt(pow(x-m1,2) + pow(y-m2,2));
            
            if(radius == rad){
                cout << "Punkt auf dem Rand" << endl;
            } else if(radius < rad) {
                cout << "Punkt liegt im Kreis" << endl;
            } else {
                cout << "Punkt liegt NICHT im Kreis" << endl;
            }
        }
  
};
template<typename T, typename S>
istream& operator>>(istream& is, Kreis<T,S>& k) {
  T x,y;
  S r;
  is >> x >> y >> r;
  k.setMittelpunkt(x,y);
  k.setRad(r);
  return is;
} 

template<typename T, typename S>
ostream& operator<<(ostream& os, const Kreis<T,S>& k) {
  os << "Mittelpunkt: (" << k.getX() << "," << k.getY() << "), Radius: " << k.getRad();
  return os;
}


int main() {
  Kreis<int,double> k1(1,1,1.5);
  cout << "Kreis k1: " << k1 << endl;
 
  k1.berechne_flaecheninhalt();
  k1.berechne_umfang();

  Kreis<double,double> k2(0.0,0.0,0.0);
  cout << "Kreis k2 eingeben: ";
  cin >> k2;
  cout << "Kreis k2: " << k2 << endl;
  k2.berechne_flaecheninhalt();
  k2.berechne_umfang();

  cout << "Einen Punkt eingeben: ";
  double x,y;
  cin >> x >> y;
  k2.ist_im_kreis(x,y);
 
  return 0;
}
