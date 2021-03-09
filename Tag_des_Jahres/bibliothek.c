#include <stdio.h>
#include <stdlib.h>
#include "bibliothek.h"


int day_of_the_year(struct dateS date){
    return 0;
}
void input_date(struct dateS *date){
    printf("Bitte Tag eingeben:");
    scanf("%d",&date->day);
    printf("Bitte Monat eingeben:");
    scanf("%d",&date->month);
    printf("Bitte Tag eingeben:");
    scanf("%d",&date->year);
}

//Funktion überprüft ob die übergebene Zahl:
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
*Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
*Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
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
int exists_date(struct dateS date){

    return 0;
}
























