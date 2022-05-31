#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

void bin(int num){
    int b1{},i{};
    vector<int>s;
    while(num!=0){
        b1=num%2;
        num=num/2;
        s.push_back(b1);
        i+=1; 
    }
    reverse(s.begin(),s.end());
    for(int z=0;z<s.size();z++){cout << s[z];}
}
int main(){
    int num{};
    cout << "enter a Number: ";
    cin >> num;
    bin(num);
}