#ifndef OBSTHAENDLER_H
#define OBSTHAENDLER_H
#include <iostream>

using namespace std;
// klasse eig. abstract jedoch klappt dann dym. array nicht,
// es sei denn man löst es mit einem vector, doch diesen darf man nicht verwenden
class Artikel{
    private:
        int artikelnummer;
    public:
    // setter / getter
        void set_artikelnummer(int a){ artikelnummer = a; }
        int get_artikelnummer(){ return artikelnummer; }
    // virtual methods
        virtual void print_Preis(){ cout << "Fehler bei Preisabfrage..." << endl; }
        virtual double get_Preis(){ cout << "Fehler bei Preisabfrage..." << endl; }
        virtual void info(){ cout << "Fehler bei Infoabfrage..." << endl; }
        virtual double get_menge(){ cout << "Fehler bei Mengeabfrage..." << endl; }  
        virtual string get_herkunft(){ cout << "Fehler bei Herkunftsanfrage..." << endl; }
};
class Apfel: public Artikel{
    private:
        string sorte;
        double preis_pro_kg;
        double kg_aller_aepfel;
    public:
    // constructors
        Apfel(int art_nr, string sorte, double p_kg, double kg_all): sorte(sorte), preis_pro_kg(p_kg), kg_aller_aepfel(kg_all) {
            set_artikelnummer(art_nr);
        }

    // setter / getter
        double get_Preis(){ return preis_pro_kg; }
        double get_menge(){ return kg_aller_aepfel; }

    // methods
        void print_Preis(){ cout << preis_pro_kg << endl; }

        void info(){
            cout << "Aepfel der Sorte: " << "[" << sorte << "]" << ", " << "Artikelnummer:" << get_artikelnummer() << endl;
            cout << "Preis pro Kilo: " << preis_pro_kg << "[Euro]" << ", " << "Menge: " << kg_aller_aepfel << endl;
            cout << "----------------------------------------------------------------------\n" << endl;
            cout << endl;  
        } 
};

class Ananas: public Artikel{
    private:
        string herkunft;
        double ananas_preis_pro_stk;
        int ananas_anzahl;
    public:
    // constructors
        Ananas(int art_nr, string h, double p_stk,  double a_anz): herkunft(h), ananas_preis_pro_stk(p_stk), ananas_anzahl(a_anz) {
            set_artikelnummer(art_nr);
        }

    // setter / getter
        double get_Preis(){ return ananas_preis_pro_stk; }
        double get_menge(){ return (double)ananas_anzahl; }
        string get_herkunft(){ return herkunft; }

    // methods
        void print_Preis(){
            if(herkunft == "Brasilien"){
                cout << "Sonderpreis" << ananas_preis_pro_stk/2 << endl;

            } else {
                cout << ananas_preis_pro_stk << endl;    
            }
        }

        void info(){
            cout << "Ananas aus: " << "[" << herkunft << "]" << ", " << "Artikelnummer:" << get_artikelnummer() << endl;
            cout << "Preis pro Stueck: " << ananas_preis_pro_stk << "[Euro]" << ", " << "Menge: " << ananas_anzahl << " Stk." << endl;
            cout << "***Sonderpreis***: " << "2 fuer 1" <<  endl;
            cout << "----------------------------------------------------------------------\n" << endl;
            cout << endl;  
        } 
};

#endif

