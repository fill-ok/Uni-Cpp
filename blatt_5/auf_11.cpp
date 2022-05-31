#include<iostream>
#include<iomanip>

template<typename T>
T f(const T& a, const T& b) {
return a+b;
}

template<typename T>
T f(const T& a, const T& b) {
return (a==b)?"same" : "not same";
}

template<typename T, class S>
T prod(T a, T b) {
return a*b;
}

int main(){
    prod<'x',2>();
}