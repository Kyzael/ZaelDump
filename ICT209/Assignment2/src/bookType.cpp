#include "../include/bookType.h"

bookType::bookType()
{

}

bookType::bookType(unsigned I)
{
    ISBN = I;
}

bookType::bookType(unsigned I, string t, string a )
{
    title = t;
    publisher = "";
    setAuthors(a);
    ISBN = 0;
    stock = 0;
    price = 0.00;
}

void bookType::setDatePublished(string input)
{
    unsigned found;
    do
    {
        found = input.find("/");
        input.erase( found, 1 );

    }while (found != string::npos);

    //published = new Date(input);
}

string bookType::getDatePublished()
{
    stringstream ss;
    ss << published.GetDay() << '/' << published.GetMonthName() << '/' << published.GetYear();
    return ss.str();
}

void bookType::setAuthors(string list)
{
    authors=0;
    authorList.clear();
    stringstream ss(list);
    string str;

    while(getline(ss,str,',') && authors < MAXAUTHORS)
    {
        authorList.push_back(str);
        authors++;
    }

}

string bookType::getAuthors()
{
    stringstream ss;
    for(unsigned i = 0; i < authors; i++)
    {
        ss << authorList[i] << ',';
    }
    return ss.str();
}

bool bookType::operator== ( const bookType& other )
{
    return(ISBN == other.ISBN);
}

bool bookType::operator< ( const bookType& other )
{
    return(ISBN < other.ISBN);
}
bool bookType::operator> ( const bookType& other )
{
    return(ISBN > other.ISBN);
}

ostream & operator <<( ostream & os, const bookType & Bk )
{
  os << Bk.ISBN;

  return os;

}

bookType bookType::operator+ ( unsigned & val )
{
    stock = stock + val;

    return(*this);
}

bookType bookType::operator- ( unsigned & val )
{
    stock = stock - val;

    return(*this);
}
