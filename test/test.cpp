#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <string>
#include <cctype>
#include <random>
#include <time.h>
#include <cstring>
#include <typeinfo>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <list>
#include <algorithm>

using namespace std;

int binary_search(vector<int>& v, int search_term, int begin, int end){
    if(end >= begin){
        int mid = begin + (end - begin) / 2;

        if(v[mid] == search_term){ return mid; }
        if(v[mid] > search_term){ return binary_search(v, search_term, begin, mid-1); }
        else{ return binary_search(v, search_term, mid+1, end); }

    } else { return -1;}
}

int all_for_loops(vector<int>& v, int search_term){
      for_each(v.begin(), v.end(), [&v,&search_term](auto const& it){
            return 3;
            });
}
class Kunde {
  private:
    string vorname;
    string nachname;
    float umsatz;
    float rabatt;

  public:
    Kunde(string v, string n, float u, float r)
      : vorname(v), nachname(n), umsatz(u), rabatt(r) { }
   
    string get_vorname() const { return vorname; }
    string get_nachname() const { return nachname; }
    float get_umsatz() const { return umsatz; }
    float get_rabatt() const { return rabatt; }
    
    void set_umsatz(float u) { umsatz = u; }
    void set_rabatt(float r) { rabatt = r; }

    friend ostream& operator<<(ostream&, const Kunde& k);
};
bool check(){
    for(int i=0;i<2;i++){
        if( i == 0){
            return 0;
        }
        if ( i == 1){
            return 1;
        }
}
       
   }
int main(){

   vector<int> v { 8,3,5,9,45,5,1,3 };
    string c = "hall";
    string b = "hal";

    if(c == b){
        cout << "true";
    } else{
        cout << "false";
    }


 
   
}
   // range based for-loop
   //---------------------
   // for(int& it: v){
   //    int i = &it - &v[0];

   //    cout << i << " "; 
   // }

   // for-loop by using iterator
   //---------------------
   // for (it = v.begin(); it != v.end(); ++it) {
   //    auto i = distance(v.begin(), it); 
      
   //    cout << *it << " ";
   // }

   // for-each + lambda
   // ---------------------
   //    for_each(v.begin(), v.end(), [&v](auto const& it){
   //       auto i = &it -&v[0];
   //       cout << it << " ";
   //  });