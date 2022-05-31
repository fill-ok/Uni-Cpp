#include "mannschaft.hpp"


int main(){
    Mitglied m("first member");
    Mitglied mm("second member");
    Mitglied mmm("third member");
    
    Mannschaft M("Bayern");
    
    M.add_new_member(m);
    M.add_new_member(mm);
    M.add_new_member(mmm);

    cout << M;
   
    M[1];

    M.print_vec();



}