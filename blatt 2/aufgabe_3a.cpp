#include <cstdlib> 
#include <ctime>
#include <iostream>

using namespace std;

int main() {
  double*** matrix;
  int dim;
  int n;

  cout << "Dimension eingeben: ";
  cin >> dim;
  cout << "Anzahl Matritzen ausgeben: ";
  cin >> n;

for(int k=0;k<n;k++){
  //Speicher fuer dim x dim  Matrix anfordern
  matrix = new double**[dim](); //(double**)malloc(sizeof(double*)*dim);
  for(int i=0 ; i<dim ; i++) {
    matrix[i] = new double*[dim]();
    for(int j=0;j<dim;j++){
      matrix[i][j] = new double[n](); //(double*)malloc(sizeof(double)*dim);
    } 
  }
  //Mit Zufallswerten fuellen
  srand(time(NULL));
  for(int i=0;i<dim;i++){
    for(int j=0;j<dim;j++){
      for(int z=0; z<dim;z++){
        matrix[i][j][z] = (double)rand();
      }
    }
       
  }
  //Ausgeben
  cout << endl;
  cout << "Erzeugte Matrix: " << endl; 
  for(int i=0 ; i<dim ; i++) {
    for(int j=0 ; j<dim ; j++) { 
      for(int z=0;z<n;z++){
        cout << matrix[i][j][z] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  
  //Speicher wieder freigeben
  for(int i=0 ; i<dim ; i++) {
    for(int j=0;j<dim;j++){
      delete[] matrix[i][j]; //free(matrix[i]);
    }
    delete[] matrix[i]; //free(matrix);
  }
  delete[] matrix;
}
  return 0;
}