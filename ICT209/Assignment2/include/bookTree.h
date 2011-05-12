#ifndef BOOKTREE_H
#define BOOKTREE_H

#include <iostream>
#include <string>
#include "binarySearchTree.h"
#include "bookType.h"

class bookTree:public bSearchTreeType<bookType>
{
    public:

    bookType getBook(unsigned ISBN);

    bool bookSearch(unsigned ISBN);

	void printBookList() const;

    protected:

    private:

    void searchBookList(bookType &search, nodeType<bookType>* &current) const;

};

#endif // BOOKTREE_H
