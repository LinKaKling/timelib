#include <stdio.h>
#include <stdlib.h>
#include "bibliothek.h"

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

//�berpr�ft ob g�ltiges Datum vom 1.1.1582 bis zum 31.12.2400 �bergeben wurde (return 1 -> g�ltig)
int exists_date(struct dateS date){
    if(date.year < 1582 || date.year > 2400 || date.month < 1 || date.month > 12 || date.day < 1 || date.day > get_days_for_month(date)){
        return 0;
    }
    return 1;
}

//Fordert den/die Bediener*in auf ein g�ltiges Datum vom 1.1.1582 bis zum 31.12.2400 einzugeben bis dies geschieht :-D (nutzt exists_date())
void input_date(struct dateS *date){
    do{
        printf("Bitte geben sie ein gueltiges Datum vom 1.1.1582 bis zum 31.12.2400 ein... \n");
        printf("Bitte Tag eingeben: ");
        scanf("%d",&date->day);
        fflush(stdin);
        printf("Bitte Monat eingeben: ");
        scanf("%d",&date->month);
        fflush(stdin);
        printf("Bitte Jahr eingeben: ");
        scanf("%d",&date->year);
        fflush(stdin);
    }while(!exists_date(*date));

}

int day_of_the_year(struct dateS date){

    return 0;
}





















