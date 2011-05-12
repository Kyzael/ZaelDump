#include "../include/memberType.h"

memberType::memberType(unsigned val)
{
    name = "";
    ID = val;
}

memberType::memberType(unsigned val, string input)
{
    name = input;
    ID = val;
}

bool memberType::operator== ( const memberType& other )
{
    return(ID == other.ID);
}

bool memberType::operator< ( const memberType& other )
{
    return(ID < other.ID);
}
bool memberType::operator> ( const memberType& other )
{
    return(ID > other.ID);
}

ostream & operator <<( ostream & os, const memberType & M )
{
  os << '(' << M.ID << ')' << M.name;

  return os;

}
