#include <iostream>
using namespace std;

void f(int& a, int& b) {
cout << "Beginn von f: " << a << "," << b << endl;
a -= b;
b *= 2;
cout << "Mitte von f: " << a << "," << b << endl;
g(a,b);
cout << "Ende von f: " << a << "," << b << endl;
}
void g(int a, int& b) {
cout << "Beginn von g: " << a << "," << b << endl;
a *= 3;
b += a;
cout << "Mitte von g: " << a << "," << b << endl;
h(a,b);
cout << "Ende von g: " << a << "," << b << endl;
}
void h(int& a, int b) {
cout << "Beginn von h: " << a << "," << b << endl;
a = b;
cout << "Ende von h: " << a << "," << b << endl;
}

int main(){
    int x = 2;
int y = 3;
f(x,y);
cout << "Main: " << x << "," << y << endl;
}