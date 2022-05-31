#include <iostream>
#include <iomanip>
#include "loeser.hpp"

using namespace std;

int main() {
  double b[n], x[n];
  double A[n][n];

  //Matrix A und rechte Seite mit Werten fuellen
  for(int i=0 ; i<n ; i++) {
    b[i] = 1.0;
    for(int j=0 ; j<n ; j++)
      if(i>j) A[i][j] = i+1; else A[i][j] = j+1;
  }

  // lu(A);

  // solve(A,b,x);

  cout << setprecision(10) << endl;
  cout << "Loesungsvektor:" << endl;
  for(int i=0 ; i<n ; i++)
    cout << x[i] << endl;
  cout << endl;

  return 0;
}
