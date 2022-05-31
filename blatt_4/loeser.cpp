#include <iostream>
#include <iomanip>
#include <loeser.hpp>

void lu(double A[n][n]) { 
  for(int k=0 ; k<n ; k++) {
    for(int i=k+1 ; i<n ; i++) {
      A[i][k] /= A[k][k];
      for(int j=k+1 ; j<n ; j++)
        A[i][j] -= A[i][k] * A[k][j];
    }    
  }
}

//Bestimmt Loesung x des Gleichungssystems aus LU-Zerlegung
//und rechter Seite b
void solve(double LU[n][n], double* b, double* x) {
  double y[n];

  for(int i=0 ; i<n ; i++) {
    y[i] = b[i];
    for(int j=0 ; j<i ; j++)
      y[i] -= LU[i][j]*y[j];
  }

  for(int i=n-1 ; i>=0 ; i--) {
    x[i] = y[i];
    for(int j=n-1 ; j>i ; j--)
      x[i] -= LU[i][j]*x[j];
    x[i] /= LU[i][i];
  }
}

