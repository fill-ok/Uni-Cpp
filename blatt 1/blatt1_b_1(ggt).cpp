#include <iostream>
using namespace std;
int ggt(int a, int b){if (b==0)return a;
    else return ggt(b, a%b);
}
int main(){cout << ggt(45,345);}