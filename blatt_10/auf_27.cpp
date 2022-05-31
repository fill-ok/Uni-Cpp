#include <iostream>

using std::cout;
using std::endl;

class Berechnung{
    public:
        virtual int berechne() = 0;
};
class Subtraktion: public Berechnung{
    private:
        int op1;
        int op2;
    public:
        Subtraktion(int a, int b) : op1(a), op2(b) {}

        int berechne() { return op1-op2; }
};
class Addition: public Berechnung {
    private:
        int op1;
        int op2;
    public:
        Addition(int a, int b) : op1(a), op2(b) {}

        int berechne() { return op1+op2; }
};

int main(){
    Addition a(1,2);
    Subtraktion s(2,3);

    cout << a.berechne() << endl; //Addition soll ausgefuehrt werden
    
    cout << s.berechne() << endl; //Subtraktion soll ausgefuehrt werden
}