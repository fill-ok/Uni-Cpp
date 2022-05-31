#ifndef TEILNEHMERLISTE_H
#define TEILNEHMERLISTE_H
#include "student.hpp"
#include <list>
#include <vector>

class Teilnehmerliste{
    private:
        list<Student> teilnehmer_liste;
        string pruefer;
        string klausur_name;
    public:
    // contructors
        Teilnehmerliste(string p, string k_n): pruefer(p), klausur_name(k_n) {}
    // methods
        void add_teilnehmer(Student& s_add){
            teilnehmer_liste.push_back(s_add);
        }

        void delete_teilnehmer(Student& s_delete) {
            int tmp{};
            vector<Student> vector = list_to_vec(teilnehmer_liste);

            for(int i=0;i<vector.size();i++){
                if(vector[i].get_martrikelnummer() == s_delete.get_martrikelnummer()){
                    tmp = i;
                }
                teilnehmer_liste.erase(next(teilnehmer_liste.begin(),tmp)); // important for exam
            }
        }

        // void sort(){
        //     teilnehmer_liste.sort(operator<())
        // }

        vector<Student> list_to_vec(list<Student>& l){
            vector<Student>v;
            for(Student &i: l){
                v.push_back(i);
            }
            return v;
        }

};


#endif