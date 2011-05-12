#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include<sstream>

using namespace std;

struct month
{
    string name;
    unsigned days;
};

const month Months[12] = {{ "January", 31 },{ "Febuary", 28 }, { "March", 31 }, { "April", 30 },
                          { "May", 31 }, { "June", 30 }, { "July", 31 }, { "August", 31 },
                          { "September", 30 }, { "October", 31 }, { "November", 30}, { "December", 31}};

class Date
{
public:


    Date();
    Date(unsigned day, unsigned mon, unsigned year);
    Date(string input);

    void setDate(string date);
    string getDate();

    unsigned GetDay();
    void SetDay(unsigned val);

    unsigned GetMonth();
    string GetMonthName();
    void SetMonth(unsigned val);

    unsigned GetYear();
    void SetYear(unsigned val);

    friend ostream & operator <<( ostream & os, const Date & Da );

    Date operator+ (unsigned & val);
    Date operator- (unsigned & val);


private:
    unsigned  D, M, Y;

    void stripInput(string input);

    void addDays(unsigned val);

    void removeDays(unsigned val);
};

#endif // DATE_H
