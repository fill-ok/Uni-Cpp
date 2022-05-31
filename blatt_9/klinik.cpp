#include <iostream>
#include <string>

using namespace std;

class Person{
    private:
        string vorname;
        string nachname;
    public:
    // constructors
        Person(){}
        Person(string v, string n): vorname(v), nachname(n) {}
    // setter / getter
        void set_vorname(string vorname_new){ vorname = vorname_new; }
        void set_nachname(string nachname_new){ nachname = nachname_new; }
        string get_vorname(){ return vorname; }
        string get_nachname(){ return nachname; }    
    //  operators
         friend ostream& operator<< (ostream& stream, Person p){
            stream << "Klasse: Person" << endl;
            stream << "Vorname: " << p.get_vorname() << endl;
            stream << "Nachname: " << p.get_nachname() << endl;
            stream << "------------------------------------------------" << endl;
            stream << endl;
            return stream;
        }    
};

class Klinikmitarbeiter : public Person{
    protected:
        int personalnummer;
    public:
    // setter / getter
        void set_personalnummer(int personalnummer_new){ personalnummer = personalnummer_new; }
        int get_personalnummer(){ return personalnummer; }
    // operators
        friend ostream& operator<< (ostream& stream, Klinikmitarbeiter& k){
            stream << "Klasse: Klinikmitarbeiter" << endl;
            stream << "Personalnummer: " << k.personalnummer << endl;
            stream << "------------------------------------------------" << endl;
            stream << endl;
            return stream;
        }
};
//------------------------------------------------------------------
class Patient : public Person{
    private:
        string krankenkasse;
        int patientennummer;

    public:
        Patient(string v, string n, string k, int p) {
            set_vorname(v);
            set_nachname(n);
            krankenkasse = k;
            patientennummer = p;
        }

        friend ostream& operator<< (ostream& stream, Patient& pa){
            stream << "Klasse: Patient" << endl;
            stream << "Vorname: " << pa.get_vorname() << endl;
            stream << "Nachname: " << pa.get_nachname() << endl;
            stream << "Krankenkasse: " << pa.krankenkasse << endl;
            stream << "Patientennummer: " << pa.patientennummer << endl;
            stream << "------------------------------------------------" << endl;
            stream << endl;
            return stream;
        }
};
// -----------------------------------------------------------------
class Arzt: public Klinikmitarbeiter {
    private:
        string fachgebiet;

    public:
        Arzt(string v, string n, int p, string f) {
            set_vorname(v);
            set_nachname(n);
            set_personalnummer(p);
            fachgebiet = f;
        }

        friend ostream& operator<< (ostream& stream, Arzt a){
            stream << "Klasse: Arzt" << endl;
            stream << "Vorname: " << a.get_vorname() << endl;
            stream << "Nachname: " << a.get_nachname() << endl;
            stream << "Personalnummer: " << a.get_personalnummer() << endl;
            stream << "fachgebiet: " << a.fachgebiet << endl;
            stream << "------------------------------------------------" << endl;
            stream << endl;
            return stream;
        }
};

class Pfleger: public Klinikmitarbeiter {
    private:
        string station;

    public:
        Pfleger(string v, string n, int p, string s) {
            set_vorname(v);
            set_nachname(n);
            set_personalnummer(p);
            station = s;
        }
        
        friend ostream& operator<< (ostream& stream, Pfleger pf){
            stream << "Klasse: Pfleger" << endl;
            stream << "Vorname: " << pf.get_vorname() << endl;
            stream << "Nachname: " << pf.get_nachname() << endl;
            stream << "Personalnummer: " << pf.get_personalnummer() << endl;
            stream << "Station: " << pf.station << endl;
            stream << "------------------------------------------------" << endl;
            stream << endl;
            return stream;
        }
};

int main() {

  Patient pa("Meike", "Muster","AOK",535353);
  Person pe(pa);
  Arzt a("John", "Dorian", 12345, "Allgemeinmediziner");
  Pfleger pf("Peter", "Paulsen", 54321, "A1");
  Klinikmitarbeiter m(pf);

  cout << pa << pe << a << pf << m << endl;


    return 0;
}
