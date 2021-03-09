/*
*Headerdatei enthält struct und Funktionsprototypen
*Kasimir Klinger 09.03.2021
*/

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

struct dateS
{
    int day;
    int month;
    int year;
};

int day_of_the_year(struct dateS date);
void input_date(struct dateS *date);
int is_leapyear(int year);
int get_days_for_month(struct dateS date);
int exists_date(struct dateS date);


#endif // TIME_H_INCLUDED
