#include<iostream>
#include<iomanip>
#include <vector>
#include<numeric>
#include "sort_namespace.h"

int main(){
    int arr_int[9]={3,5,64,2,5,6,2,5,47}, sum{},ascii{};
    double arr_dou[9]={5.2,6.2,5.7,8.1,45.76,234.1,3.5,32.5,6.9}, product{};
    char arr_char[9]={'d','q','t','s','k','u','q','m','v',};
    int n=9;
    bool calc=false;

    std:: cout << "sotieren und rechnen? ";
    std:: cin >> calc;

    for(int k=0;k<3;k++){
        std::cout << std::endl;
        switch(k){
            case 0:
                sortieren::printArray_before(arr_int,9);
                sortieren::quickSort(arr_int,0,n-1);
                sortieren::printArray(arr_int,9);
                if(calc==true){
                    std::vector<int> v(arr_int, arr_int + sizeof arr_int / sizeof arr_int[0]);
                    sum=sortieren_und_rechnen::sort_and_calc_int(v);
                    std:: cout << "Summe des Arrays:  " << sum << std::endl;
                }
                break;
            case 1:
                sortieren::printArray_before(arr_dou,9);
                sortieren::quickSort(arr_dou,0,n-1);
                sortieren::printArray(arr_dou,9);
                 if(calc==true){
                    std::vector<double> v(arr_dou, arr_dou + sizeof arr_dou / sizeof arr_dou[0]);
                    product=sortieren_und_rechnen::sort_and_calc_dou(v);
                    std:: cout << "Produkt des Arrays:  " << product <<  std::endl;
                }
                break;
            case 2:
                sortieren::printArray_before(arr_char,9);
                sortieren::quickSort(arr_char,0,n-1);
                sortieren::printArray(arr_char,9);
                 if(calc==true){
                    std::vector<int> v(arr_char, arr_char + sizeof arr_char / sizeof arr_char[0]);
                    ascii=sortieren_und_rechnen::sort_and_calc_char(v);
                    std:: cout << "Summe der ASCII-Werte:  " << ascii << std::endl;
                }
                break;
        }
    }    
}