#include <iostream>
using namespace std;

void pali(string digit){
    int len=digit.length(),z{1},c{};
    for(int i=0;i<len/2;i++){
        if(digit[i]==digit[len-z]){c+=1;}        
        else{cout << "false" << endl; break;}
        z+=1;
    }
    if(c==len/2){cout << "true";}
}
int main(){
    string digit{};
    int len{};
    cout << "enter a number: ";
    cin >> digit;
    pali(digit);
}