#include "kunden.hpp"

int main() {
  vector<Kunde*> kunden;

  //Kundendaten anlegen
  kunden.push_back(new Kunde("Hans", "Muster", Adresse("Musterstr.", "2", "12345", "Musterstadt"), 184.39, 5.0));
  kunden.push_back(new Kunde("Brigitte", "Mustermann", Adresse("Beispielstr.", "10", "54321", "Beispielstadt"), 0.0, 0.0));
  kunden.push_back(new Kunde("John", "Doe", Adresse("Inkognitostr.", "154", "42855", "Remscheid"), 8746.86, 10.0));
  kunden.push_back(new Kunde("Jane", "Doe", Adresse("Inkognitostr.", "154", "42855", "Remscheid"), 3224.23, 7.5));
  kunden.push_back(new Kunde("Max", "Meier", Adresse("Klischeestr.", "34a", "01122", "Oststadt"), 24.65, 1.5));

  cout << "Liste der Kunden: " << endl << endl;
  ausgabe(kunden);
  cout << "---------------------" << endl << endl;

  for_each(kunden.begin(), kunden.end(), bind(rabatt_erhoehen(), _1, 1.5));

  cout << "Nach Erhoehung des Rabatts: " << endl << endl;
  ausgabe(kunden);
  cout << "---------------------" << endl << endl;

  cout << "Alle Kunden mit PLZ die mit 01 anfaengt: " << endl << endl;
  cout << **(find_if(kunden.begin(), kunden.end(), Plz_beginnt_mit("01"))) << endl;
  cout << "---------------------" << endl << endl;

  vector<Kunde*>::iterator it;
  it = remove_if(kunden.begin(), kunden.end(), Wohnt_in_und_umsatz_kleiner(it,"Beispielstadt", 100.0));
  kunden.erase(it, kunden.end());

  cout << "Nach Loeschen aller Kunden aus Beispielstadt mit Umsatz kleiner 100.0: " << endl << endl;
  ausgabe(kunden);
  cout << "---------------------" << endl << endl;

  for_each(kunden.begin(), kunden.end(), umsatz_summieren());
  cout << "Summierter Umsatz: " << get_sum << endl;

  return 0;
}
