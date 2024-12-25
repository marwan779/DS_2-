/*
                    Documentation Part
===================================================================
    @file           : DoubleLinkedList.h
    @brief          : Contains the Structure Of Nodes & 
                      Prototypes of the Double Linked List 
                      functions DS
===================================================================

*/

/*====================== Start Of File Gaurd ======================*/

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

/*====================== Includes ======================*/

#include <iostream>
#include "Book.h"
using namespace std;

struct Node
{
    Book Data;
    Node *Next;
    Node *Back;
};

/*================ Prototypes Of Functions ================*/


class DoubleLinkedList
{
public:
    DoubleLinkedList();
    void InsertAtBegnning(const Book &Item);
    Book* Search(const string Title);
    int Lenght();
    void DeleteNode(const int Location);
    void PrintForward();
    void PrintByCategory(string Category);
    void PrintBook(Book book);
    void Free();
    bool BookExist(const string Title);
    void Sort();
    bool IsEmpty();


protected:
    Node *Head;
    Node *Tail;
    int Count;

        

};


/*====================== End Of File Gaurd ======================*/

#endif
