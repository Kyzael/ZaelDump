#ifndef BOOKTYPE_H
#define BOOKTYPE_H

#include <stdio.h>
#include <string.h>
#include<list>
#include "Date.h"
#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

const unsigned MAXAUTHORS = 4;

class bookType
{
    public:
        bookType();
        bookType(unsigned I);
        bookType(unsigned I, string t, string a );

        string getTitle() { return title; }
        void setTitle(string val) { title = val; }

        string getPublisher() { return publisher; }
        void setPublisher(string val) { publisher = val; }

        unsigned getISBN() { return ISBN; }
        void setISBN(unsigned val) { ISBN = val; }

        unsigned getStock() { return stock; }
        void setStock(unsigned val) { stock = val; }

        float getPrice() { return price; }
        void setPrice(float val) { price = val; }

        void setDatePublished(string input);
        string getDatePublished();

        void setAuthors(string list);
        string getAuthors();

        bool operator== ( const bookType& other );
        bool operator< ( const bookType& other );
        bool operator> ( const bookType& other );

        bookType operator+ (unsigned & val);
        bookType operator- (unsigned & val);

        friend ostream & operator <<( ostream & os, const bookType & Bk );


    protected:
    private:
        string title;
        string publisher;
        unsigned ISBN;
        unsigned stock;
        float price;
        unsigned authors;
        vector<string> authorList;
        Date published;

};

#endif // BOOKTYPE_H
