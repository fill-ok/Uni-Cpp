#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void print(int n,int z){
    cout << "|";
    for(int i=1;i<=n;i++){
        printf("%2.d * %2.d = %2.d |",i,z,i*z);
    } 
    cout << endl;
}
int main(){
    int n{},z{};
    cout << "enter a Number: ";
    cin >> n;
    for(z=1;z<=n;z++){
        print(n,z);  
    }
}