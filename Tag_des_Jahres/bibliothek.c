#include <stdio.h>
#include <stdlib.h>
#include "bibliothek.h"

//Funktion überprüft ob die übergebene Zahl:
//unter 1582 ist -> -1
//als Jahr ein Schaltjahr ist -> 1
//oder kein Schaltjah ist -> 0
//Fallback -> -2
int is_leapyear(int year)
{

    if(year < 1582)
    {
        return -1;
    }

    if (year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
            {
                return 1; //durch 400 teilbar
            }
            else
            {
                return 0; //nicht durch 400 teilbar
            }
        }
        else
        {
            return 1; //nicht durch 100 teilbar
        }
    }
    else
    {
        return 0; //nicht durch 4 teilbar
    }
    return(-2);
}

/*
*Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
*Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
*/
int get_days_for_month(struct dateS date)
{
    int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};//Tage der Monate eines nicht-Schaltjahres (! 0 = Januar , 11 = dezember !)
    if (is_leapyear(date.year) == -1 || date.month < 1 || date.month > 12)
    {
        return -1;
    }
    if (date.month == 2 && is_leapyear(date.year) == 1)
    {
        return 29; //wenn der Monat Februar und das Jahr ein Schaltjahr ist hat der Monat 29 Tage
    }
    else //ansonsten wie im Array
    {
        return daysPerMonth[date.month-1]; //date.month fägt bei 1 an zu zählen und der Array bei 0
    }

    return 0; //Fallback sollte nie eintreten
}

//überprüft ob gültiges Datum vom 1.1.1582 bis zum 31.12.2400 übergeben wurde (return 1 -> gültig)
int exists_date(struct dateS date)
{
    if(date.year < 1582 || date.year > 2400 || date.month < 1 || date.month > 12 || date.day < 1 || date.day > get_days_for_month(date))
    {
        return 0;
    }
    return 1;
}

//Fordert den/die Bediener*in auf ein gültiges Datum vom 1.1.1582 bis zum 31.12.2400 einzugeben bis dies geschieht :-D (nutzt exists_date())
void input_date(struct dateS *date)
{
    do
    {
        printf("Bitte geben sie ein gueltiges Datum vom 1.1.1582 bis zum 31.12.2400 ein... \n");
        printf("Bitte Tag eingeben: ");
        scanf("%d",&date->day);
        fflush(stdin);
        printf("Bitte Monat eingeben: ");
        scanf("%d",&date->month);
        fflush(stdin);
        printf("Bitte Jahr eingeben: ");
        scanf("%d",&date->year);
        fflush(stdin); //dies verhindert Endlosschleife durch eingabe von Buchstaben
    }
    while(!exists_date(*date));

}

//Summiert alle Tage verstrichener Monate und verstrichene Tage des aktuellen Monats des entsprechenden Jahres :-D Der wievielte Tag des Jahres ist das?
int day_of_the_year(struct dateS date)
{
    if (!exists_date(date))
    {
        return -1;
    }
    struct dateS t; //hier so gelöst um später get_days_for_month(t) zu nutzen und so bei Schaltjahren richtig zu rechnen (t.day wird ignoriert)
    t.year = date.year;
    t.month = 1;
    int count = 0;
    while(t.month <= date.month)
    {
        if(t.month < date.month)
        {
            count += get_days_for_month(t);
        }
        else
        {
            count += date.day;
        }
        t.month += 1;
    }
    return count;
}





















