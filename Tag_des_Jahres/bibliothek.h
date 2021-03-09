#ifndef BIBLIOTHEK_H_INCLUDED
#define BIBLIOTHEK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

struct dateS{
    int day;
    int month;
    int year;
};

int day_of_the_year(struct dateS date);
void input_date(struct dateS *date);
int is_leapyear(int year);
int get_days_for_month(struct dateS date);
int exists_date(struct dateS date);

#endif // BIBLIOTHEK_H_INCLUDED
