#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

template<class T>
T dot(T *x, T *y,int n) {
  // aufgabe b) vergleicht ob geg: vektoren gleich sind
  int count{};
  if(is_same<T,bool>::value){
      for(int i=0;i<n;i++){
          if(x[i]==y[i]){count+=1;}
      }
      if(count == n){return true;}
      else{return false;}
  }
  else{
    T res = 0;
    
    for(int i=0 ; i<n ; i++)
        res += x[i]*y[i];
    return res; 
  }
}

template<class S,class T>
void matvec(S** A,T*x,S* erg,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            erg[i]+=A[i][j]*x[i];
        }
    }
}

template<class S, class T>
void matmat(S** A, T** B, S** C,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            C[i][j]+=A[i][j]*B[i][j];
        }
    }
}

template<class S>
void out(S** erg, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            setprecision(2); 
            cout << setw(10) << erg[i][j] << " | ";
        }
        cout << endl;
    }
}


int main() {
    int n{};
    std:: cout << "Bitte n waehlen: ";
    std:: cin >> n;
    //Vektoren
    int *xi = new int[n], *yi = new int[n];
    float *xf = new float[n], *yf = new float[n];
    double *xd = new double[n], *yd = new double[n]; 
    bool *xb = new bool[n], *yb = new bool[n];

    //Matrizen
    int **I = new int*[n];
    float **F = new float*[n];
    double **D1 = new double*[n];
    double **D2 = new double*[n];
    double **erg = new double*[n];
    for(int i = 0; i < n; ++i) {
        I[i] = new int[n];
        F[i] = new float[n];
        D1[i] = new double[n];
        D2[i] = new double[n];
        erg[i] = new double[n];
    }

    //Teilaufgabe a)
    //Vektoren und Matrizen mit Werten fuellen  
    for(int i=0 ; i<n ; i++) {
        xi[i] = i+1;    yi[i] = i-1;
        xf[i] = 0.1f*i; yf[i] = 0.25f*i;
        xd[i] = M_PI*i; yd[i] = 1e-10*i;
        xb[i] = (i%2 == 0); yb[i] = (i%3 == 0);

        for(int j=0 ; j<n ; j++) {
        if(i==j) I[i][j] = 1; else I[i][j] = 0;
        if(i>j)  F[i][j] = 0.2*i; else F[i][j] = 0.2*j;
        D1[i][j] = M_PI*(i+j);
        }
    }
    cout << setprecision(2);

    cout << "Skalarprodukt von int Vektoren: "    << dot(xi,yi,n) << endl;
    cout << "Skalarprodukt von float Vektoren: "  << dot(xf,yf,n) << endl;
    cout << "Skalarprodukt von double Vektoren: " << dot(xd,yd,n) << endl;
    cout << "Vektoren gleich?: " << dot(xb,yb,n) << endl;
    cout << endl;

    // aufgabe c
    matvec(D1,xf,xd,n);
    cout << "Matrix-Vektor-Produkt mit double und float: ";
    for(int i=0;i<n;i++){cout << xd[i] << " ";} cout << endl;
    matvec(F,xi,xf,n);
    cout << "Matrix-Vektor-Produkt mit float und int: ";
    for(int i=0;i<n;i++){cout << xf[i] << " ";} cout << endl;
    cout << endl;
    //Teilaufgabe d)
   
    matmat(D1,I,erg,n);
    cout << "Matrix-Matrix-Produkt mit double und int: " << endl;
    out(D2,n); cout << endl;
    matmat(D1,F,erg,n);
    cout << "Matrix-Matrix-Produkt mit double und float: " << endl;
    out(D2,n);

    for(int i = 0 ; i < n ; i++){
        delete [] I[i] ;
        delete [] F[i];
        delete [] D1[i];
        delete [] D2[i];
    }
    delete [] I;
    delete [] F;
    delete [] D1;
    delete [] D2;
    return 0;
}
