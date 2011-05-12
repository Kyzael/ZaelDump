#include "../include/Date.h"
// Date.CPP - Date Class Implementation

Date::Date()
{
    //sets all values to 0
    D = 0;
    M = 0;
    Y = 0;
}

Date::Date(unsigned day, unsigned mon, unsigned year)
{
    D = day;
    M = mon;
    Y = year;
}

Date::Date(string input)
{
    stripInput(input);
}

void Date::setDate(string date)
{
    stripInput(date);
}
string Date::getDate()
{
    stringstream ss;
    ss << D << '/' << Months[M - 1].name << '/' << Y;
    return ss.str();
}

unsigned Date::GetDay()
{
    return D;
}

void Date::SetDay(unsigned val)
{
    D = val;
}

unsigned Date::GetMonth()
{
    return M;
}

string Date::GetMonthName()
{
    return Months[M - 1].name;//decrement M by 1 when finding the corresponding month in the array.
}

void Date::SetMonth(unsigned val)
{
    M = val;
}

unsigned Date::GetYear()
{
    return Y;
}

void Date::SetYear(unsigned val)
{
    Y = val;
}


ostream & operator <<( ostream & os, const Date & Da )
{
  os << "  Date:  "
     << Da.D << '/'
     << &Months[Da.M - 1].name << '/'
     << Da.Y;

  return os;
}

Date Date::operator+ ( unsigned & val )
{
    unsigned difference = D + val - Months[M - 1].days; //works out if the days i am adding is more than what is left in the current month.
        if(difference < 0) //if -  then we have gone into next month.
        {
            M++; //so increase the month.
            addDays(difference * -1); //send the days left to be added to recursive function
        }
        else
            D = D + val;  //set the day.

    return (*this);
}

Date Date::operator- (unsigned &val)
{
    unsigned difference = D - val;
    if(difference < 0)
    {
        M--;
        removeDays(difference * -1);
    }
    else
        D = D - val;

    return (*this);
}

void Date::addDays(unsigned val)
{
    if(Months[M -1].days < val)
    {
        val = val - Months[M - 1].days;
        M++;
        addDays(val);
    }
    else
        D = val;
}

void Date::removeDays(unsigned val)
{
    if(Months[M -1].days < val)
    {
        val = val - Months[M - 1].days;
        M--;
        removeDays(val);
    }
    else
        D = val;
}

void Date::stripInput(string input)
{                               //for example input of 16032010
        D = atoi((input.substr(0,2)).c_str()); //16  turns the string unsignedo a c string, creates a substring to split for the day, converts the substring into integer representaion.
        M = atoi((input.substr(2,2)).c_str()); //03
        Y = atoi((input.substr(4,4)).c_str());  //2010
}
