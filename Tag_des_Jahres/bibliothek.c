#include <stdio.h>
#include <stdlib.h>

struct dateS{
    int day;
    int month;
    int year;
};

int day_of_the_year(){
    return 0;
}
void input_date();

//Funktion �berpr�ft ob die �bergebene Zahl:
//unter 1582 ist -> -1
//als Jahr ein Schaltjahr ist -> 1
//oder kein Schaltjah ist -> 0
//Fallback -> -2
int is_leapyear(int year){

    if(year < 1582){
        return -1;
    }

    if (year % 4 == 0){
            if(year % 100 == 0){
                if(year % 400 == 0){
                    return 1; //durch 400 teilbar
                }else{
                    return 0; //nicht durch 400 teilbar
                }
            }else{
                return 1; //nicht durch 100 teilbar
            }
    }else{
        return 0; //nicht durch 4 teilbar
    }
    return(-2);
}

/*
*Die Funktion bestimmt f�r einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
*Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden ber�cksichtigt.
*/
int get_days_for_month(struct dateS date){
    int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};//
    if (is_leapyear(date.year) == -1 || date.month < 1 || date.month > 12){
        return -1;
    }
    if (date.month == 2 && is_leapyear(date.year) == 1){
        return 29;
    }else{
        return daysPerMonth[date.month];
    }

    return 0;
}
int exists_date(){
    return 0;
}
