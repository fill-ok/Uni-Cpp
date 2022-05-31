#include <iostream>
#include <algorithm> 
#include <random>
#include <time.h>


using namespace std;

class Wurf{
    friend class Wurfverwalutng;
    private:
        unsigned int wurf;
    public:
    // constructor
        Wurf(){
            srand(time(NULL));
            wurf = rand() % 6 + 1;
        }
        Wurf(unsigned int wurf_enter){
            wurf = wurf_enter;
        }
    // methods
        ostream& operator << (ostream& stream_enter){
            return stream_enter << wurf << endl;
        }

};