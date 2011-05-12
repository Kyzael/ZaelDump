#include "..\include\bookTree.h"

    bookType bookTree::getBook(unsigned ISBN)
    {

    nodeType<bookType> *location;
    location = this->root;
    bookType temp;
    temp.setISBN(ISBN);


    searchBookList(temp, location);

	return temp;
    }

    bool bookTree::bookSearch(unsigned ISBN)
    {
        bool found = false;
        bookType searchItem;
        searchItem.setISBN(ISBN);
        found = this->search(searchItem);

	return found;
    }

	void bookTree::printBookList() const
	{
	    this->inorderTraversal();
	}

    void bookTree::searchBookList(bookType &search, nodeType<bookType>* &current) const
    {
    if(current == NULL)
    {
        cout << "Book not found!";
    }
    else
    {
         if (current->info == search)
             search = current->info;
          else
              if (current->info > search)
                  current = current->llink;
              else
                  current = current->rlink;
    }
    }


