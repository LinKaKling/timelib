/*
*Das Programm "Tag des Jahres" soll bei Eingabe eines Datums ausgeben der wievielte Tag des jeweiligen Jahres ist.
*Dabei werden die Spezifikationen aus "Tag des Jahres - Spezifikation" großteils berücksichtigt, teilweise leicht abgeändert (z.B. bei den Übergabeparametern).
*Weitere Infos werden später im Readme festgehalten
*Kasimir Klinger 09.03.2021
*/
#include <stdio.h>
#include <stdlib.h>
#include "bibliothek.h"


int main()
{
    struct dateS date;
    input_date(&date);
    printf("Tag: %d \n",date.day);
    printf("Monat: %d \n",date.month);
    printf("Jahr: %d \n",date.year);
    if(exists_date(date) == 1){
        printf("Jo");
    }else{
        printf("else");
    }
    return 0;
}
