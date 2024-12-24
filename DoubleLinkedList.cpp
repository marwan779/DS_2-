#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;

/**
 * Constructor to initialize a DoubleLinkedList object.
 * Sets Head and Tail pointers to nullptr and Count to 0.
 */

DoubleLinkedList::DoubleLinkedList()
{
    Head = nullptr;
    Tail = nullptr;
    Count = 0;
}

/**
 * Checks if the double linked list is empty.
 *
 * @returns true if the list is empty, false otherwise.
 */

bool DoubleLinkedList::IsEmpty()
{
    return (Count == 0 ? true : false);
}

/**
 * Checks if a book with the given title exists in the double linked list.
 *
 * @param Title The title of the book to search for.
 *
 * @returns true if the book with the given title exists in the list, false otherwise.
 */

/*Complexity: O(n)*/
bool DoubleLinkedList::BookExist(const string Title)
{
    Node *Current = Head;
    bool Result;
    while (Current != nullptr)
    {
        if (Title == Current->Data.Title)
        {
            Result = true;
            break;
        }
        else
        {
            Current = Current->Next;
        }
    }
    return Result;
}


/**
 * Inserts a book at the beginning of the double linked list.
 *
 * @param Item The book to be inserted.
 */


/*Complexity: O(1)*/
void DoubleLinkedList::InsertAtBegnning(const Book &Item)
{
    Node *NewNode = new Node;
    NewNode->Data = Item;
    // 1. insert when the list is empty
    if (IsEmpty())
    {
        Head = NewNode;
        Tail = NewNode;
        NewNode->Next = nullptr;
        NewNode->Back = nullptr;
    }
    else // 2. insert when the list is not empty
    {
        NewNode->Next = Head;
        NewNode->Back = nullptr;
        Head->Back = NewNode;
        Head = NewNode;
    }
    Count++;
}


/**
 * Searches for a book by title in the double linked list.
 *
 * @param Title The title of the book to search for.
 *
 * @returns The book if found; otherwise, returns an empty book object.
 */


/*Complexity: O(n)*/
Book DoubleLinkedList::Search(const string Title)
{
    Node *Current = Head;
    Book Result ;
    while (Current != nullptr)
    {
        if (Title == Current->Data.Title)
        {
            Result = Current ->Data;
            break;
        }
        else
        {
            Current = Current->Next;
        }
    }
    return Result;
}

/**
 * Gets the length of the double linked list.
 *
 * @returns The number of nodes in the list.
 */

/*Complexity: O(1)*/
int DoubleLinkedList::Lenght()
{
    return Count;
}

/**
 * Deletes a book by title from the double linked list.
 *
 * @param Location The Location of the book to be deleted.
 */

/*Complexity: O(Location)*/
void DoubleLinkedList::DeleteNode(const int Location)
{
    Node *Current = Head;
    Node *DeleteItem;
    if(IsEmpty())
    {
        // cout<<"\nThe List Is Embty At The Moment\n\n";
        Error = "\nThe List Is Embty At The Moment\n\n";
    }
    else
    {
        if (Location < 0 || Location > Count)
        {
            // cout << "\nthe given location is out of range\n\n";
            Error = "\nthe given location is out of range\n\n";
        }
        else
        {
            if (Location == 1 && Count > 1)
            {
                DeleteItem = Head;
                Head = Head->Next;
                Head->Back = nullptr;
                DeleteItem->Next = nullptr;
                DeleteItem->Back = nullptr;
                delete DeleteItem;
                DeleteItem = nullptr;
            }
            else if(Location == 1 && Count == 1)
            {
                DeleteItem = Head;
                DeleteItem->Next = nullptr;
                DeleteItem->Back = nullptr;
                delete DeleteItem;
                Head = nullptr;
                DeleteItem = nullptr;
            }
            else if (Location == Count)
            {
                DeleteItem = Tail;
                Tail = Tail->Back;
                Tail->Next = nullptr;
                DeleteItem->Next = nullptr;
                DeleteItem->Back = nullptr;
                delete DeleteItem;
                DeleteItem = nullptr;
            }
            else
            {
                for (int i = 1; i < Location - 1; i++)
                {
                    Current = Current->Next;
                }

                DeleteItem = Current->Next;
                Current->Next = DeleteItem->Next;
                DeleteItem->Next->Back = Current;
                DeleteItem->Next = nullptr;
                DeleteItem->Back = nullptr;
                delete DeleteItem;
                DeleteItem = nullptr;
            }
            Count--;
        }
    } 
}

/**
 * Prints the contents of the double linked list in forward order.
 * Displays details of each book including title, author, category, and price.
 */

/*Complexity: O(n)*/
void DoubleLinkedList::PrintForward()
{
    if(IsEmpty())
    {
        // cout<<"\nThe List Is Embty At The Moment\n\n";
        Error = "\nThe List Is Embty At The Moment\n\n";
    }
    else
    {
        Node *Current = Head;
        int Index = 1;
        cout << "------------------------------------\n";
        while (Current != nullptr)
        {
            cout << "Index: "<<Index<<"\n";
            cout << "Title: " << Current->Data.Title << "\n";
            cout << "Author: " << Current->Data.Author << "\n";
            cout << "Category: " << Current->Data.Category << "\n";
            cout << "Price: " << Current->Data.Price << "$\n";


            Index++;
            Current = Current->Next;
            cout << "------------------------------------\n";
        }
    }
}

/**
 * Prints all books in the specified category.
 *
 * @param Category The category to filter books by.
 */

/*Complexity: O(n)*/
void DoubleLinkedList::PrintByCategory(string Category)
{
    Node *Current = Head;
    cout<<"*******************\n";
    cout<< "Categoty: " << Category <<"\n";
    cout<<"*******************\n";

    while (Current != nullptr)
    {
        if (Current->Data.Category == Category)
        {
            cout << "Title: " << Current->Data.Title << "\n";
            cout << "Author: " << Current->Data.Author << "\n";
            cout << "Price: " << Current->Data.Price << "$\n";

            cout << "------------------------------------\n";
        }

        Current = Current->Next;
    }
}

/**
 * Prints the details of a single book.
 *
 * @param book The book to be printed.
 */

/*Complexity: O(1)*/
void DoubleLinkedList::PrintBook(Book book)
{
    cout << "------------------------------------\n";

    cout << "Title: " << book.Title << "\n";
    cout << "Author: " << book.Author << "\n";
    cout << "Category: " << book.Category << "\n";
    cout << "Price: " << book.Price << "$\n";

    cout << "------------------------------------\n";
}

/**
 * Frees the memory of the double linked list.
 * Prompts the user for confirmation before deleting all nodes.
 */

/*Complexity: O(n)*/
void DoubleLinkedList::Free()
{
    if(IsEmpty())
    {
        // cout<<"\nThe List Is Embty At The Moment\n\n";
        Error = "\nThe List Is Embty At The Moment\n\n";
    }
    else
    {
        char Choice;
        cout<<"Are You Sure You Want To Free The List? (press y for yes or n for no): ";
        cin>>Choice;
        if(Choice == 'y')
        {
            Node *Current = Head;
            Node *DeleteItem;
            while (Current != nullptr)
            {
                DeleteItem = Current;
                Current = Current->Next;
                delete DeleteItem;
            }

            Head = nullptr;
            Tail = nullptr;
            Count = 0;
        }
        else if(Choice == 'n')
        {
            // cout<<"Free Operation Is Canceled\n";
            Error = "Free Operation Is Canceled\n";
        }
        else
        {
            // cout<<"Enter a vaild choice\n";
            Error = "Enter a vaild choice\n";
        }
    }
    
}

/**
 * Sorts the double linked list based on the title of the books in ascending order.
 * Selection Sort Algorithm
 */

/*Complexity: O(n^2)*/
void DoubleLinkedList::Sort()
{
    if(IsEmpty())
    {
        // cout<<"\nThe Library Is List At The Moment\n\n";
        Error = "\nThe Library Is List At The Moment\n\n";
    }
    else if(Count ==1 ) {}
    else
    {
        Node *Current = Head;
        while (Current)
        {
            Node *SmallestNode = Current;
            Node *Iterator = Current->Next;

            while (Iterator)
            {
                if (Iterator->Data.Title < SmallestNode->Data.Title)
                {
                    SmallestNode = Iterator;
                }
                Iterator = Iterator->Next;
            }

            if (SmallestNode != Current)
            {
                Book Temp = Current->Data;
                Current->Data = SmallestNode->Data;
                SmallestNode->Data = Temp;
            }

            Current = Current->Next;
        }
    }
    
}

