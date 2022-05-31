#ifndef KUNDE_H
#define KUNDE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std; 
using namespace std::placeholders;

class Adresse {
  private:
    string strasse;
    string hausnummer;
    string plz;
    string ort;

  public:
    Adresse(string s, string h, string p, string o)
      : strasse(s), hausnummer(h), plz(p), ort(o) { }

    string get_strasse() const { return strasse; }
    string get_hausnummer() const { return hausnummer; }
    string get_plz() const { return plz; }
    string get_ort() const { return ort; }

    friend ostream& operator<<(ostream&, const Adresse&);
};

ostream& operator<<(ostream& os, const Adresse& a) {
  os << a.strasse << " " << a.hausnummer << endl;
  os << a.plz << " " << a.ort << endl;
  return os;
}


class Kunde {
  private:
    string vorname;
    string nachname;
    Adresse adresse;
    float umsatz;
    float rabatt;

  public:
    Kunde(string v, string n, Adresse a, float u, float r)
      : vorname(v), nachname(n), adresse(a), umsatz(u), rabatt(r) { }
   
    string get_vorname() const { return vorname; }
    string get_nachname() const { return nachname; }
    Adresse get_adresse() const { return adresse; }
    float get_umsatz() const { return umsatz; }
    float get_rabatt() const { return rabatt; }
    
    void set_umsatz(float u) { umsatz = u; }
    void set_rabatt(float r) { rabatt = r; }

    friend ostream& operator<<(ostream&, const Kunde& k);
};

ostream& operator<<(ostream& os, const Kunde& k) {
  os << k.vorname << " " << k.nachname << endl;
  os << k.adresse;
  os << "Umsatz: " << k.umsatz << " Euro" << endl;
  os << "Rabatt: " << k.rabatt << " %" << endl;
  return os;
}

void ausgabe(vector<Kunde*>& v) {
  for(unsigned int i=0 ; i<v.size() ; i++)
    cout << *(v[i]) << endl;
}

//------------------------------------------------------------------------

struct Rabatt_erhoehen{
    void operator () (Kunde& k, float new_value){
        float new_rabatt = k.get_rabatt() + new_value;
        k.set_rabatt(new_rabatt);
    }
};

struct Plz_beginnt_mit{
    void operator () (Kunde& k, string plz){

        for(int i=0;i<plz.size();++i){
            if(k.get_adresse().get_plz()[i] == plz[i]){
                if(i == plz.size()-1){
                    cout << k << endl;
                }
            } else {
                break;
            }

        }
    }
};

struct Wohnt_in_und_umsatz_kleiner{
    void operator () (const Kunde& k, string check_wohnt, float check_umsatz){
        string check_1{};
        string check_2{};

        if(k.get_adresse().get_ort() == check_wohnt){ check_1 = "true"; } else { check_1 = "false"; }
        if(k.get_umsatz() < check_umsatz ){ check_2 = "true"; } else { check_2 = "false"; }

        cout << "wohn  in [" << check_wohnt << "]: " << check_1  << endl;
        cout << "umsatz kleiner als [" << check_umsatz << "]: " << check_2  << endl;
    }
};

static float get_sum{};

struct umsatz_summieren{
   void operator () (const Kunde& k){
       get_sum += k.get_umsatz();
   } 
};


#endif