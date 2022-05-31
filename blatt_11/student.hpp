#ifndef STUDENT _H
#define STUDENT_H
#include <iostream>
using namespace std;

const char* bool_true = "true";
const char* bool_false = "false";

class Student{
    private:
        string vorname;
        string nachname;
        string martrikelnummer;
    public:
    // constructors
        Student() {} 
        Student(string v, string n, string m_n): vorname(v), nachname(n), martrikelnummer(m_n) {}
    // setter / getter
        string get_vorname() { return vorname; }
        string get_nachname() { return nachname; }
        string get_martrikelnummer() { return martrikelnummer;  }
    // methods
    // operators
        // vergleicht zwei Studenten
        friend const char* operator == (Student& s1, Student s2){
            if(s1.martrikelnummer == s2.martrikelnummer){
                return bool_true;
            }else {
                return bool_false;
            }
        }

        friend Student& operator < (Student&s1, Student& s2){
            string n1 = s1.nachname;
            char char_nachnachme_1 = n1[0];

            string n2 = s2.nachname;
            char char_nachnachme_2 = n1[0];
     
            if(char_nachnachme_1 < char_nachnachme_2){
                return s1;
            } else {
                return s2;
            }
        }
        
        friend ostream& operator<< (ostream& stream, Student& s){
            stream << "Klasse: Student";
            stream << "Vorname: " << s.vorname << endl;
            stream << "Nachname: " << s.nachname << endl;
            stream << "Martrikel-nr:" << s.martrikelnummer << endl;
            stream << "--------------------------------------------\n" << endl;
            return stream;
        }
};
#endif