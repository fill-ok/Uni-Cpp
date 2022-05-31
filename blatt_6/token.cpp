#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;
const string allowed = ("+-*/().cossintanpiex");

char str_to_chr(string& str){
   char c = str[0];
   return c;
}

int main(){
    string formel,str_convert;
    int is_digit{},fail{};
    cout << "Formel eingeben: ";
    cin >> formel;

    vector<string>v;
    string formel_print;
    for(int i=0;i<formel.length();i++){
        if(allowed.find(formel[i]) != -1){
            if(formel[i] == 'c' || formel[i] == 's' || formel[i] == 't'){
                if(formel[i] == 'c' && formel[i+1] == 'o' && formel[i+2] == 's'){ str_convert = "cos";}
                if(formel[i] == 's' && formel[i+1] == 'i' && formel[i+2] == 'n'){ str_convert = "sin";}
                if(formel[i] == 't' && formel[i+1] == 'a' && formel[i+2] == 'n'){ str_convert = "tan";}
                v.push_back(str_convert);
                str_convert.clear();
                i+=2;
            } else{
                if(formel[i] == 'p'){
                    if(formel[i] == 'p' && formel[i+1] == 'i'){ str_convert = "pi";}
                    v.push_back(str_convert);
                    str_convert.clear();
                    i+=1;
                } else{
                    if(formel[i] == 'o' || formel[i] == 'i' || formel[i] == 'a' || formel[i] == 'n'){
                        cout << "invalid symbols" << endl;
                        fail = 1;
                        break;
                    } else{
                        str_convert = formel[i];
                        v.push_back(str_convert);
                        str_convert.clear();
                    }
                }
            }  
        } else{
            if(isdigit(formel[i]) == 1){
                str_convert.push_back(formel[i]);              
                v.push_back(str_convert);
                str_convert.clear();
            } else{                    
                cout << "invalid symbols" << endl;
                fail = 1;
                break;
            } 
        }
    }
    if(fail != 1){
        for(int i=0;i<v.size();i++){
            cout << v[i];
        
            if(v[i] == "." && isdigit(str_to_chr(v[i-1])) == 1 && isdigit(str_to_chr(v[i+1])) == 1){}
            else if(isdigit(str_to_chr(v[i])) == 1 && isdigit(str_to_chr(v[i+1])) == 1){}
            else if(isdigit(str_to_chr(v[i])) == 1 && v[i+1] == "."){}
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}