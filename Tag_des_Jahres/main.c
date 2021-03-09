/*
*Das Programm "Tag des Jahres" soll bei Eingabe eines Datums ausgeben der wievielte Tag des jeweiligen Jahres ist.
*Dabei werden die Spezifikationen aus "Tag des Jahres - Spezifikation" großteils berücksichtigt, teilweise leicht abgeändert (z.B. bei den Übergabeparametern).
*Weitere Infos werden später im Readme festgehalten
*Kasimir Klinger 09.03.2021
*/
#include <stdio.h>
#include <stdlib.h>
#include "time.h"


int main()
{
    struct dateS date;
    input_date(&date);
    int dayOfYear = day_of_the_year(date);
    printf("Am eingegebenen Datum ist es der %d -te Tag des Jahres",dayOfYear);
    return 0;
}
