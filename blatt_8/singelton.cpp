#include <iostream>
using namespace std;

class Singelton{
    private:
        static Singelton* obj;

        Singelton(){
            obj++;
        };

        ~Singelton(){
            delete []obj;
        }
    public: 
        static Singelton* get_obj(){
            if(obj == 0){
                obj = new Singelton();
            }
            return obj;
        }
};
Singelton* Singelton::obj = 0;


int main(){
    Singelton* first = Singelton::get_obj();
    Singelton* second = Singelton::get_obj();

    cout << first << endl;
    cout << second << endl;
}