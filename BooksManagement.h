#ifndef BOOKSMANAGEMENT_H
#define BOOKSMANAGEMENT_H

#include <iostream>
#include "DoubleLinkedList.cpp"
#include "Book.h"


class BooksManagement
{
    public:
        void AddBookTolibrary();
        void PrintBooks();
        void PrintByCategory();
        void SearchForBook();
        void UpdateBook();
        void DeleteBook();
        void FreeLibrary();
        void SortLibrary();
    private:
        DoubleLinkedList Library;
};

#endif