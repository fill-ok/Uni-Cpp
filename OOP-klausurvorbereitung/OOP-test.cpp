#include <iostream>
using namespace std;

int main(){
    int a[3] = {1,3,5};
    int b[3] = {1,3,3};

    if (equal(begin(a),end(a),begin(b))){
        cout << "true";
    }
    else{
        cout << "false";
    }
}