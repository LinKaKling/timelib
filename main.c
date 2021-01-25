/**
 *dies wird eine Funktionssammlung zum üben von Funktionen und git
 *erstellt von Kasimir Klinger
 *am 25.01.2021
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
int day_of_the_year(int day, int month, int year)
{
    int TageImFebruar = 28 , return_day = 0;

    if (year % 4 == 0){ //Schaltyear?
            if(year % 100 == 0){
                if(year % 400 == 0){
                    TageImFebruar = 29; //durch 400 teilbar
                }
            }else{
                TageImFebruar = 29; //nicht durch 100 teilbar
            }
    }
    // Tage pro Monat
    int TageProMonat[12] = {31,TageImFebruar,31,30,31,30,31,31,30,31,30,31};

    if (month >= 1 && month <= 12)
    {
        if (day >= 1 && day <= TageProMonat[month-1]){
            int y = 0;
            do{
                if (y < month -1){
                    return_day += TageProMonat[y];
                }else{
                    return_day += day;
                }
                y++;
            }while(y < month);
            return return_day;
        }else{
            return -1;
        }
    }else{
        return -1;
    }
    return -2;
}

int main()
{
    printf("Tag des yeares: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
