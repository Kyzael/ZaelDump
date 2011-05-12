#ifndef MEMBERTYPE_H
#define MEMBERTYPE_H

#include <string>

using namespace std;

class memberType
{
    public:
        memberType(unsigned val);
        memberType(unsigned val, string input);

        string getName() { return name; }
        void Setname(string val) { name = val; }
        unsigned GetID() { return ID; }

        bool operator== ( const memberType& other );
        bool operator< ( const memberType& other );
        bool operator> ( const memberType& other );

        friend ostream & operator <<( ostream & os, const memberType & M );

    private:
        string name;
        unsigned ID;
};

#endif // MEMBERTYPE_H
