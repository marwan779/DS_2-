#include <iostream>
#include "DoubleLinkedList.h"
#include <iomanip>
#include "termcolor.hpp"
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
    bool Result = false;
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
 * Searches for a book by title in the double linked list using
 * two pointers algorithm.
 *
 * @param Title The title of the book to search for.
 *
 * @returns The book if found; otherwise, returns an empty book object.
 */


/*Complexity: O(n)*/
Book *DoubleLinkedList::Search(const string Title)
{
    Node *first = Head;
    Node *last = Tail;
    Book *Result = nullptr;

    while (first != nullptr && last != nullptr && first != last->Next)
    {
        if (first->Data.Title == Title)
        {
            Result = &(first->Data);
            return Result;
        }   
            

        if (last->Data.Title == Title)
        {
            Result = &(last->Data);
            return Result;
        }
            

        first = first->Next;
        last = last->Back;
    }
    cout <<termcolor::bright_white;
    cout <<termcolor::on_bright_red;//background
    cout << "Error: Book not found!\n";
    cout <<termcolor::reset;
    return (Result);
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
        cout <<termcolor::bright_white;
                    cout <<termcolor::on_bright_red;
                    cout << "\nError: the given location is out of range!\n\n";
                    cout <<termcolor::reset;
    }
    else
    {
        if (Location < 0 || Location > Count)
        {
           cout <<termcolor::bright_white;
            cout <<termcolor::on_bright_red;
            cout << "\nError: The given location is out of range\n\n";
            cout <<termcolor::reset;
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
        cout <<termcolor::bright_white;
                cout <<termcolor::on_bright_red;
                cout<<"\nError: The List Is Empty At The Moment!\n\n";
                cout <<termcolor::reset;
    }
    else
    {
        Node *Current = Head;
        int Index = 1;

        cout<<"+-------+--------------------+--------------------+---------------+----------------+\n";
        cout<<"| Index |        Title       |       Author       |    Category   |      Price     |\n";
        cout<<"+-------+--------------------+--------------------+---------------+----------------+\n";
        while (Current != nullptr)
        {
            
             cout << "| " <<termcolor::bright_cyan<< setw(5) << Index <<termcolor::bright_white<< " | "
            <<termcolor::bright_magenta <<setw(18) << Current->Data.Title <<termcolor::bright_white<< " | "
            <<termcolor::yellow << setw(18) << Current->Data.Author<<termcolor::bright_white << " | "
            <<termcolor::cyan << setw(13) << Current->Data.Category <<termcolor::bright_white<< " | "
            <<termcolor::bright_green << setw(13) << fixed << setprecision(2) << Current->Data.Price<<"$" << termcolor::bright_white<<" |\n";

            Index++;
            Current = Current->Next;
            cout<<termcolor::bright_white;
            cout<<"+-------+--------------------+--------------------+---------------+----------------+\n";
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
    cout<<"Categoty: " << Category <<"\n";
    cout<<"*******************\n";

    cout<<"+--------------------+--------------------+----------------+\n";
    cout<<"|        Title       |       Author       |      Price     |\n";
    cout<<"+--------------------+--------------------+----------------+\n";
    while (Current != nullptr)
    {
        if (Current->Data.Category == Category)
        {
            cout <<"| " <<termcolor::bright_magenta <<setw(18) << Current->Data.Title <<termcolor::bright_white<< " | "
            <<termcolor::yellow << setw(18) << Current->Data.Author <<termcolor::bright_white<< " | "
            <<termcolor::bright_green << setw(13) << fixed << setprecision(2) << Current->Data.Price<<"$" <<termcolor::bright_white<< " |\n";


            cout<<"+--------------------+--------------------+----------------+\n";
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
   cout<<termcolor::bright_white;
    cout<<"+--------------------+--------------------+---------------+----------------+\n";
    cout<<"|        Title       |       Author       |    Category   |      Price     |\n";
    cout<<"+--------------------+--------------------+---------------+----------------+\n";
    cout << "| " <<termcolor::bright_magenta<<setw(18) << book.Title <<termcolor::bright_white<< " | "
         <<termcolor::yellow<< setw(18) << book.Author <<termcolor::bright_white<< " | "
            <<termcolor::bright_cyan<< setw(13) << book.Category <<termcolor::bright_white<<termcolor::bright_white<<" | "
            <<termcolor::bright_green<< setw(13) << fixed << setprecision(2) << book.Price<<"$" << " |\n";

    cout<<termcolor::bright_white;
    cout<<"+--------------------+--------------------+---------------+----------------+\n";
    cout<<termcolor::reset;
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
                cout <<termcolor::on_bright_red;
                cout <<termcolor::bright_white;
                cout<<"\nError: The List Is Empty At The Moment!\n\n";
                cout <<termcolor::reset;
    }
    else
    {
        char Choice;
        cout <<termcolor::on_bright_red;
        cout <<termcolor::bright_white;
        cout<<"Are You Sure You Want To Free The List? (press (Y/y) for yes or (N/n) for no): ";
        cout <<termcolor::reset;
        cin>>Choice;
        if(Choice == 'y' || Choice == 'Y')
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
            cout <<termcolor::bright_white;
            cout <<termcolor::on_bright_green;
            cout <<"Free is Done\n";
            cout <<termcolor::reset;
        }
        else if(Choice == 'n' || Choice == 'N')
        {
                       cout <<termcolor::bright_white;
                       cout <<termcolor::on_bright_green;
                       cout<<endl;
                       cout<<"Free Operation Is Canceled\n";
                       cout <<termcolor::reset;
        }
        else
        {
                        cout <<termcolor::on_bright_red;
                        cout <<termcolor::bright_white;
                        cout<<"Error: Enter a vaild choice!\n";
                        cout <<termcolor::reset;
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
                cout <<termcolor::on_bright_red;
                cout <<termcolor::bright_white;
                cout<<"\nError: The Library Is Empty At The Moment!\n\n";
                cout <<termcolor::reset;
    }

    else if(Count ==1 )

    {
        cout <<termcolor::bright_white;
        cout <<termcolor::on_bright_green;
        cout <<"Sort Done\n";
        cout <<termcolor::reset;
    }
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

        cout <<termcolor::bright_white;
        cout <<termcolor::on_bright_green;
        cout <<"Sort Done\n";
        cout <<termcolor::reset;
    }
    
}

