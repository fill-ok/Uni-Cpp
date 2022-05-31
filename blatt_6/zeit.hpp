#ifndef ZEIT_H
#define ZEIT_H
#include "datum.hpp"
#include <iostream>
#include <iomanip>

class Zeit{
    private:
        int hour;
        int minute;
        Datum date;
    public:
    // constructors
    Zeit()
        : hour(0), minute(0) {}    
    Zeit(unsigned  int hour_enter, unsigned int minute_enter){
        check_enter_of_time(hour_enter,minute_enter);
    }
    Zeit(unsigned int hour_enter, unsigned int minute_enter, Datum& datum_enter){
        check_enter_of_time(hour_enter,minute_enter);
        this->date = datum_enter;
    }
     Zeit(unsigned int day_enter, unsigned int month_enter, unsigned int year_enter, unsigned int hour_enter, unsigned int minute_enter){
        this->date.set_day(day_enter);
        this->date.set_month(month_enter);
        this->date.set_year(year_enter);

        check_enter_of_time(hour_enter,minute_enter);
    }
    // destructor
    //  ~Zeit(){}

    // methods
    void check_enter_of_time(unsigned  int hour_enter, unsigned int minute_enter){
        int fail{};
        if(minute_enter >= 0 && minute_enter <= 59){this->hour = hour_enter;} else{fail+=1;}
        if(hour_enter >= 0 && hour_enter <= 23){this->minute = minute_enter;} else{fail+=1;}

        if(fail > 0){reset_time();}
    }
    void  print_date_time(){
        cout << date.get_day() << ". " << months[date.get_month()-1] << " " << date.get_year() << " [";
        cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << "]"<< endl;
    }

    void  reset_time(){
        this->date.Datum::reset_values();
        this->minute = 0;
        this->hour = 0;
        cout << "invlaid enter please try again! " << endl;
    }
    // void  set_date(const Datum &obj){
    //     this->date = obj;
    // }
    // add any minutes
    Zeit& operator += (const int time_enter){
        unsigned int day{}, month{}, year{};
        for(int i=0;i<time_enter;i++){
            if(minute >= 59){
                minute = 0;
                if(hour >= 23){
                    hour = 0;

                    date.update_date();
                }else{
                    hour += 1;
                    minute = 0;
                } 
            }
            else{
                minute += 1;
            }
        }
        return *this;
    }
    unsigned int get_hour(){
        return hour;
    }
    unsigned int get_minute(){
        return minute;
    }
};
#endif 