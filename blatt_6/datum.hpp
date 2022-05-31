#ifndef DATUM_H
#define DATUM_H
#include <iostream>
#include <algorithm> 

using namespace std;

const char *months[12]={"Januar","Februar","Maerz","April","Mai","Juni","Juli","August","September","Oktober","November","Dezember"};
const int days_in_months[13]= {31,28,31,30,31,30,31,31,30,31,30,31,29};

class Datum{
    private:
        unsigned int day;
        unsigned int month;
        unsigned int year;
    public:
        // contructors
        Datum(){
            this->day = 1;
            this->month = 1;
            this->year = 1900;
        }
        Datum(int day_enter, int month_enter, int year_enter){
            int fail{}, fail_1{}; 
            //check valid enter of day
            if(month_enter%2 == 0 && month_enter <= 7 && month_enter !=2 && day_enter <= 30 && day_enter > 0) {this->day = day_enter;} else{fail+=1;}
            if(!(month_enter%2 == 0) && month_enter <= 7 && month_enter !=2 && day_enter <= 31 && day_enter > 0){this->day = day_enter;} else{fail+=1;} 
            if(month_enter == 2 && day_enter > 0 && day_enter < 29){this->day = day_enter;} else{fail+=1;} cout << fail << endl;
            if(month_enter == 2 && day_enter == 29){
                if(((year_enter%4==0) && (year_enter%100!=0)) || (year_enter%400==0)){this->day = day_enter;} else{fail+=1;}} else{fail+=1;}
            if(month_enter%2 == 0 && month_enter > 7 && day_enter <= 31 && day_enter > 0){this->day = day_enter;} else{fail+=1;}
            if(month_enter%2 != 0 && month_enter > 7 && day_enter <= 30 && day_enter > 0){this->day = day_enter;} else{fail+=1;}
            
            // check valid enter of month
            if(month_enter > 0 && month_enter <= 12){this->month = month_enter;} else{fail_1+=1;}

            //check valid enter of year
            if(year_enter >= 1900){this->year = year_enter;} else{fail_1+=1;}

            // fail check
            if(fail > 5 || fail_1 > 0){reset_values();}               
        }
        // destructor 
        // Datum(){
        //     delete[]  day;
        //     delete[]  month;
        //     delete[] year;
        // };

        void print() {
            cout << day << ". " << months[month-1] << " " << year << endl;
        }
        Datum& get_date(){
            this->day = day;
            this->month = month;
            this->year = year;
            return *this;
        }
        unsigned int  get_day(){
            return day;
        }
        unsigned int  get_month(){
            return month;
        }
        unsigned int  get_year(){
            return year;
        }
        void set_day(unsigned int &set_day){
            this-> day = set_day;
        }
         void set_month(unsigned int &set_month){
            this-> month = set_month;
        }
         void set_year(unsigned int &set_year){
            this-> year = set_year;
        }
        // check if the year is a leap year
        bool leap_year(int year_enter){
            if(((year_enter%4==0) && (year_enter%100!=0)) || (year_enter%400==0)){
                return 1;
            } else {return  0;} 
        }
        void  reset_values(){
            this->day = 1;
            this->month = 1;
            this->year = 1900;
            cout << "invlaid enter please try again! " << endl;
        }

        Datum& set_values(){
            this->day = 1;
            this->month = 1;
            this->year = 1900;
            return *this;
        }
        //transfer date to other date
        Datum set_datum(Datum& old_date){
            this-> day = old_date.day;
            this-> month = old_date.month;
            this-> year = old_date.year;
            return *this; 
        }
        // check if day & month are same
        void same(Datum& other_date){
            if(day == other_date.day && month == other_date.month){
                cout << "both are same!" << endl;
            } else{
                cout << "both are NOT same!" << endl; 
            }
        }
        // add any days 
        Datum& operator += (const int day_add){
            int border = days_in_months[month-1];
            if(month == 2 && day == 28 && leap_year(year) == 1){border = 29;} 
            for(int i=0;i<day_add;i++){
                if(day == border){
                    if(month == 2 && leap_year(year) == 1){
                        day += 1;
                    }
                    day = 1;
                    if(month < 12){
                        month += 1;
                    } else {
                        month = 1;
                        year += 1;
                    }
                } else{
                    this-> day += 1;
                }
            }
            return *this;
        }
        Datum& update_date(){
          int border = days_in_months[month-1];
            if(month == 2 && day == 28 && leap_year(year) == 1){border = days_in_months[12];} 
            
                if(day == border || (day == 29 && month == 2)){
                    day = 1;
                    if(month < 12){
                        month += 1;
                    } else {
                        month = 1;
                        year += 1;
                    }
                } else{
                    day += 1;
                }
            return *this;
        }
};
#endif