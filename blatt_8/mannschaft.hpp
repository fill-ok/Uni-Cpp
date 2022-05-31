#ifndef MANSCHAFFT_H
#define MANNSCHAFT_H
#include <iostream>
#include <cstring>
#include <vector>
#include "mitglied.hpp"

using namespace std;

const int max_member = 1000;

class Mannschaft{
    private:
        string name;
        int points;
        int member_count;
        vector<string>vec_of_member;
    public:
        // constructors
            Mannschaft(string s) : name{s}, points(0), member_count(0), vec_of_member(0) {};

            // copy constructor 
            Mannschaft(const Mannschaft& old_obj) 
                : name(old_obj.name), points(old_obj.points), member_count(old_obj.member_count), vec_of_member(old_obj.vec_of_member) {};  

        // methods
            void add_new_member(Mitglied& m){
                vec_of_member.push_back(m.get_name());
                member_count++;
            }

            void print_vec(){
                for(string i: vec_of_member){
                   cout << i << endl;
               }
            }

        // setter / getter
            string get_name(){ return name;}
            int get_points(){ return points; }
            int get_member_count(){ return  member_count; }

        // operators 
            Mannschaft& operator = (const Mannschaft& old_obj){
                name = old_obj.name;
                points = old_obj.points;
                member_count = old_obj.member_count;
                vec_of_member = old_obj.vec_of_member;
                return *this;
            }

            friend ostream& operator<< (ostream& stream, Mannschaft& m){
                stream << "Team: " << m.name << endl;
                stream << "Punkte: " << m.points << endl;
                stream << "Anzahl Mitglieder: " << m.member_count << endl;
                stream << "---------------------" << endl;
                
                return stream;             
            }

            void operator [] (int n){
                char answer{};
                string new_member;
                cout << "member on position [" << n << "]: " << vec_of_member[n] << endl;
                cout << "change member? (y/n) ";
                cin >> answer;
                if(answer == 'y'){
                    cout << "enter new member: ";
                    cin >> new_member;
                    vec_of_member[n] = new_member;
                } 
                cout << "---------------------" << endl;
            }
};
#endif


//    void add_new_member(Mitglied& m1){
//                 member_count++;
//                 Mitglied* tmp_arr = new Mitglied[member_count];
//                 if(member_count == 1){
//                     player_arr = tmp_arr;
//                 } else {
//                     memcpy(tmp_arr, player_arr, sizeof(Mitglied)*member_count);
//                     delete []player_arr;
//                     player_arr = tmp_arr;
//                 }

//                 delete []tmp_arr;

//                 player_arr[member_count-1] = m1;
//             }