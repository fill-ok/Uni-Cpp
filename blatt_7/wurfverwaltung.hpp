#include <iostream>
#include <algorithm>
#include "wuerfel.hpp"

class Wurfelverwaltung{
    private:
        unsigned int count;
        Wurf *wurf_arr; 
    public:
    // constructors
        Wurfelverwaltung(unsigned int count_enter){
            count = count_enter;
            wurf_arr = new Wurf[count];
        }
        Wurfelverwaltung(const Wurfelverwaltung &w1){
            count = w1.count;
            wurf_arr = new Wurf[count];
            for(int i=0;i<count;i++){
                wurf_arr[i] = w1.wurf_arr[i];
            }
        }
    // destructors 
        ~Wurfelverwaltung(){
            delete [] wurf_arr;
        }

    // methods
        void set_count(unsigned int count_enter){
            count = count_enter;
        }
        unsigned int get_count(){
            return count;
        }

        Wurfelverwaltung& operator = (Wurfelverwaltung &w_enter){
            count = w_enter.count;
            delete [] wurf_arr;
            wurf_arr = new Wurf[count];
            for(int i=0;i<count;i++){
                wurf_arr[i] = w_enter.wurf_arr[i];
            }
            return *this;
        }

        Wurfelverwaltung& operator += (Wurfelverwaltung &w_enter){
            int z{};
            for(int i=count;i<w_enter.count;i++){
                wurf_arr[i] = w_enter.wurf_arr[z];
                z++;
            }
        }
        Wurfelverwaltung& operator+= (Wurfelverwaltung &w_enter){
            wurf_arr[count] = w_enter.wurf_arr[0];
        }
        bool are_same(Wurfelverwaltung &w1, Wurfelverwaltung &w2){
            if(w1.count == w2.count){
                for(int i=0;i<w1.count;i++){
                    if(w1.wurf_arr[i] == w2.wurf_arr[i]){}
                    else{
                        return false;
                    }
                }
            } else{
                return false;
            }
            return true;
        }
          ostream& operator << (ostream& stream_enter){
            for(int i=0;i<count;i++){
                return stream_enter << wurf_arr[Wurf::operator<<];
            }
        }
};
