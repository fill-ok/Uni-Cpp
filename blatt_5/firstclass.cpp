#include<iostream>
#include<iomanip>
#include<string>

class Firma {
    private:
        std::string personal_num = "-1";
        std::string vor = "-1";
        std::string nach = "-1";
        std::string abteilung = "-1";
        int alter = -1;
        int id2 = -1;
    public:
    // constructor
    Firma(int id){
        this-> id2 = id;
    }
    
    int get_id(){
        return id2;
    }

    void auslesen(){
        std::cout << personal_num  << ", " << vor << " " << nach << std::endl;
        std::cout << "Alter: " << alter<< " Jahre" << std::endl;
        std::cout << "Ablteilung: " << abteilung << std::endl; 
    }

    void einlesen(){
        std::cout << "personalnumber eingeben: "; std:: cin >> personal_num;  std::cout << std::endl;
        std::cout << "vorname eingeben: "; std:: cin >> vor;  std::cout << std::endl;         
        std::cout << "nachname eingeben: "; std:: cin >> nach;  std::cout << std::endl;         
        std::cout << "abteilung eingeben: "; std:: cin >> abteilung;  std::cout << std::endl;         
        std::cout << "alter eingeben: "; std:: cin >> alter;  std::cout << std::endl;           
    }
};

int main(){
    int n{}; int id{3};
    std::cout << "anzahl mitarbeiter: "; std:: cin >> n;  std::cout << std::endl;
  
    char *personal_num_arr = new char[n];
    char *vor_arr = new char[n];
    char *nach_arr = new char[n];
    char *abteilung_arr = new char[n];
    int *alter_arr = new int[n];

    Firma m1(6);
    m1.einlesen(); 
    m1.auslesen();
   
    delete [] personal_num_arr;
    delete [] vor_arr;
    delete [] nach_arr;
    delete [] abteilung_arr;
    delete [] alter_arr;
}