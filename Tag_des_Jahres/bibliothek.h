#ifndef BIBLIOTHEK_H_INCLUDED
#define BIBLIOTHEK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

int day_of_the_year(struct dateS date);
void input_date();
int is_leapyear(int year);
int get_days_for_month(struct dateS date);
int exists_date();

#endif // BIBLIOTHEK_H_INCLUDED
