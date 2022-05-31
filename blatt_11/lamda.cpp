#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

int all_for_loops(vector<int>& v, int search_term, int n){
    switch(n){
        case 0:
            // indexbasierte for-schleife
            for(int i=0;i<v.size();++i){
                if(v[i] == search_term){
                    return i;
                } else if(i+1 == v.size()){
                    return  -1;
                }
            }
            break;
        
        case 1:
             by using Iterators 
            vector<int>::iterator it;
            for(it = v.begin(); it < v.end(); ++it){
                auto i = distance(v.begin(), it);

                if(*it == search_term){
                    return i;
                } else if(i+1 == v.size()){
                    return -1;
                }
            }
            break;
        case 2:
              //  range based for-loop
            for(int &it: v) {
                int i = &it - &v[0]; // index

                if(it == search_term){
                    return i;
                } else if(i+1 == v.size()){
                    return -1;
                }
            }
            break;
        
        case 3:
            // for_each + lambda
            for_each(v.begin(), v.end(), [&v,&search_term](auto const& it){
                auto i = &it -&v[0]; // index

                if(it == search_term){
                    return i;
                } else if(i+1 == v.size()){
                    return -1;
                }
            });
            break;
    }

}

int binary_search(vector<int>& v, int search_term, int begin, int end){
    if(end >= begin){
        int mid = begin + (end - begin) / 2;

        if(v[mid] == search_term){ return mid; }
        if(v[mid] > search_term){ return binary_search(v, search_term, begin, mid-1); }
        else{ return binary_search(v, search_term, mid+1, end); }

    } else { return -1;}
}



int main()
{
    vector<int> v { 8,3,5,9,4,5,1,3 };

    // Aufgabenteil a) Suche nach der Zahl 4 in vector v mittels 3 verschiedener Schleifen
    int pos = -1;
    int search_term = 4;

    // Methode 1: For-Schleife mit Index
    pos = all_for_loops(v,search_term,0);   
    cout << search_term <<  " gefunden bei Index " << pos << " mit Indexbasierter for-Schleife" << endl;
    cout << "-------------------------------------------\n" << endl;
    pos = -1;

    // Methode 2: Iterator
    pos = all_for_loops(v,search_term,1);    
    cout << search_term <<  " gefunden bei Index " << pos << " mit for-Schleife und Iteratoren" << endl;
    pos = -1;
    cout << "-------------------------------------------\n" << endl;
    
    //Methode 3: range-based for
    pos = all_for_loops(v,search_term,2);    
    cout << search_term <<  " gefunden bei Index " << pos << " mit Ranged-based for-Schleife" << endl;
    pos = -1;
    cout << "-------------------------------------------\n" << endl;
    
    //Methode 4: for_each + lambda
    pos = all_for_loops(v,search_term,3);    
    cout << search_term <<  " gefunden bei Index " << pos << " mit Ranged-based for-Schleife" << endl;
    pos = -1;
    cout << "-------------------------------------------\n" << endl;

    // -----------------------------------------------------------------------------------------------------

    // Aufgabenteil b) Binäre Suche in sortiertem vector v
    sort(v.begin(), v.end());
    cout << "Sortierter Vector: ";
    for(int &num : v) cout << num << " ";
    cout << endl;

    search_term = 4;
    pos = binary_search(v, search_term, 0, v.size() - 1);
    cout << search_term <<  " gefunden bei Index " << pos << " mit binaerer Suche" << endl;
    

    // Aufgabenteil c) vector quadrieren mittels lambda
    vector<int> w = v;    
    auto lambda = [&w](int num) -> int {
        return num*num;
    };
    cout << "Quadrierter Vector: ";
    for(int &num : w){
        num = lambda(num);
        cout << num << " ";
    } 
    cout << endl;

    return 0;
}