#include <iostream>
#include <map>
#include "include/bookType.h"
#include "include/memberType.h"
#include "include/Date.h"
#include "include/bookTree.h"

using namespace std;

struct loan
{
    bookType *book;
    Date dueDate;
};

int main()
{
    //vector<memberType> memberList;
    map < memberType, vector<loan> > loans;
    bookTree bookList;


    bookType testBook1;
    bookType testBook2;
    bookType testBook3;

    testBook1.setISBN(2);
    testBook2.setISBN(3);
    testBook3.setISBN(1);

    bookList.insert(testBook1);
    bookList.insert(testBook2);
    bookList.insert(testBook3);

    bookType temp;
    //temp = bookList.getBook(5);
    temp = bookList.getBook(1);
    cout << '\n';
    if(bookList.bookSearch(2))
        cout << "found" << '\n';
    cout << temp;
    cout << '\n';

    bookList.printBookList();

    //loans.find(&memberList[i])->second.push_back(newloan);  example

    return(0);
}



