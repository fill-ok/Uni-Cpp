#include<iostream>
#include<iomanip>
#include<vector>
#include<valarray>
#include<cmath>
#include<string>
using namespace std;

int main(){
    double startwert{-1}, startwert_1{}, startwert_2{}, startwert_3{},
    endwert{2.6}, schrittweite{0.5}, test{}; int sigZiffern{3}, len{}, with{}, first{1}; char gleich('=');
    
    cout << "Bitte Startwert fuer x eingeben: "; cin >> startwert;
    cout << "Bitte Endwert fuer x eingeben: "; cin >> endwert;
    cout << "Bitte Schrittweite fuer x eingeben: "; cin >> schrittweite;
    cout << "Wieviele signifikante Ziffern sollen angezeigt werden: "; cin >> sigZiffern;

    test=startwert;
    const int startwert_0=startwert;
    while(test<endwert){
        test=test+schrittweite;
        len+=1;
    }
    with=(2+sigZiffern+7);

    cout << endl;
    for(int i=0;i<len;i++){
        
        cout << endl;
        for(int j=0;j<1;j++){
            if(first==1){
                cout << left << setw(with-1) << "x" << "|"; 
                cout << left << setw(with-1) << "x_3" << "|";
                cout << left << setw(with-1) << "sin(x)" << "|";
                cout << left << setw(with-1) << "log(x)" << endl;
                for(int i=0;i<with*4;i++){
                    cout << left << gleich;
                }
                cout << endl;
            } first=-1;
            cout << left << showpos << scientific << setprecision(sigZiffern-1) << startwert << " |"; startwert_1=pow(startwert,3);
            cout << left << showpos << scientific << setprecision(sigZiffern-1) << startwert_1 << " |"; startwert_2=sin(startwert);
            cout << left << showpos << scientific << setprecision(sigZiffern-1) << startwert_2 << " |"; startwert_3=log(startwert);
            cout << left << showpos << scientific << setprecision(sigZiffern-1) << startwert_3; 
            } startwert+=schrittweite;   
        }        
}

// bessere lösung versuch nummer 2 

#include <iostream>
#include <iomanip>
#include <cmath>

using  namespace std;

int main(){
	int zig{3};float start{-1}, end{2.6},step{0.5}; 
	// cout << "Starwert x: "; cin >> start;
	// cout << "Endwert x: "; cin >> end;
	// cout << "Step x: "; cin >> step;
	// cout << "Zig2 x: "; cin >> zig;

	// header
	int width = 1+5+5+1;
	cout << setw(width) << left << "x" << "|";
	cout << setw(width) << left << "x^3";
	cout << setw(width) << left << "sin(x)";
	cout << setw(width) << left << "log(x)" << endl;
	for(int i=0;i<width*4;++i){ cout << "="; }
	cout << endl;

	// calculation
	for(start; start <= end ; start+=step){
		cout << left << showpos << setw(width) << setprecision(zig) << scientific << start << "|";
		cout << left << showpos << setw(width) << setprecision(zig) << scientific << pow(start,3);
		cout << left << showpos << setw(width) << setprecision(zig) << scientific << sin(start);
		cout << left << showpos << setw(width) << setprecision(zig) << scientific << log(start);	
		cout << endl;	
	}
	return 0;
}