#include <iostream>
#include "BooksManagement.h"
#include <string>

/**
 * Adds a new book to the library after getting the necessary information from the user.
 * Prompts the user for book details such as title, author, category, and price.
 * If a book with the same title already exists, it shows an error message.
 * Otherwise, the book is inserted at the beginning of the library list.
 */

void BooksManagement::AddBookTolibrary()
{
    Book book;
    int Choice;
    cout <<termcolor::on_cyan;
    cout <<termcolor::bright_white;
    cout << "Enter Book Title: ";
    fflush(stdin);
    getline(cin, book.Title);

    if (Library.BookExist(book.Title))
    {
       cout <<termcolor::bright_white;
       cout <<termcolor::on_bright_red;
       cout << "\nError: A Book With The Same Title Exists. Choice Different Title Please\n\n";
       cout <<termcolor::reset;
    }
    else
    {
        cout <<termcolor::on_cyan;
        cout <<termcolor::bright_white;
        cout << "Enter Book Author: ";
        fflush(stdin);
        getline(cin, book.Author);
        cout << "1. Fiction\n2. History\n3. Mystery\n4. Science\n";
        cout << "choice Book Category: ";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            book.Category = "Fiction";
            break;
        case 2:
            book.Category = "History";
            break;
        case 3:
            book.Category = "Mystery";
            break;
        case 4:
            book.Category = "Science";
            break;
        default:
            cout <<termcolor::bright_white;
            cout <<termcolor::on_bright_red;
            cout << "Invalid category choice. Defaulting to Fiction.\n";
            book.Category = "Fiction";
            break;
        }

        cout <<termcolor::bright_white;
        cout <<termcolor::on_cyan;
        cout << "Enter Book Price: ";
        cout <<termcolor::reset;
        cin >> book.Price;

        Library.InsertAtBegnning(book);
    }
}

/**
 * Prints all the books in the library in forward order.
 * If the library is not empty, it displays each book's details.
 */

void BooksManagement::PrintBooks()
{
    Library.PrintForward();
}

/**
 * Prompts the user to choose a book category and prints all books of that category.
 */

void BooksManagement::PrintByCategory()
{
    if(Library.IsEmpty())
    {
        cout <<termcolor::bright_white;
        cout <<termcolor::on_bright_red;
        cout<<"\nError: The Library Is Empty At The Moment\n\n";
        cout <<termcolor::reset;
    }
    else
    {
        int Choice;
        string Category;
        cout <<termcolor::yellow;
        cout << "1. Fiction\n2. History\n3. Mystery\n4. Science\n";
        cout << "choice Book Category: ";
         cout <<termcolor::reset;
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            Category = "Fiction";
            break;
        case 2:
            Category = "History";
            break;
        case 3:
            Category = "Mystery";
            break;
        case 4:
            Category = "Science";
            break;
        default:
            cout <<termcolor::bright_white;
            cout <<termcolor::on_bright_red;
            cout << "Invalid category choice. Defaulting to Fiction.\n";
            cout <<termcolor::reset;
            Category = "Fiction";
            break;
        }

        Library.PrintByCategory(Category);
    }
}

/**
 * Prompts the user to enter a book title and searches for it in the library.
 * If the book is found, its details are printed; otherwise, an error message is displayed.
 */

void BooksManagement::SearchForBook()
{
    if (Library.IsEmpty())
    {
        cout <<termcolor::bright_white;
        cout <<termcolor::on_bright_red;
        cout<<"\nError: The Library Is Empty At The Moment\n\n";
        cout <<termcolor::reset;
    }
    else
    {
        string Title;
        cout <<termcolor::bright_white;
        cout <<termcolor::on_yellow;
        cout << "Enter Book Title: ";
        cout <<termcolor::reset;
        fflush(stdin);
        getline(cin, Title);
        Book *Temp = Library.Search(Title);
        if (Temp->Title == "")
        {
            cout <<termcolor::bright_white;
            cout <<termcolor::on_bright_red;
            cout << "\nNo Book With Such Name\n\n";
            cout <<termcolor::reset;
        }
        else
        {
            Library.PrintBook(*Temp);
        }
    }
}

/**
 * Deletes a book from the library and then prompts the user to enter new book details to update it.
 */

void BooksManagement::UpdateBook()
{
    string Title;
    Book *book = nullptr;
    int Choice;

    cout << "Enter Book Title: ";
    fflush(stdin);
    getline(cin, Title);
    book = Library.Search(Title);
    if (book == nullptr)
    {
    }
    else
    {
        Library.PrintBook(*book);

        cout <<termcolor::yellow;
        cout << "\nEnter New Data\n\n";
        cout <<termcolor::yellow;

        cout << "Enter Book Title: ";
        fflush(stdin);
        getline(cin, book->Title);

        cout << "Enter Book Author: ";
        fflush(stdin);
        getline(cin, book->Author);
        cout << "1. Fiction\n2. History\n3. Mystery\n4. Science\n";
        cout << "choice Book Category: ";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            book->Category = "Fiction";
            break;
        case 2:
            book->Category = "History";
            break;
        case 3:
            book->Category = "Mystery";
            break;
        case 4:
            book->Category = "Science";
            break;
        default:
            cout << "Invalid category choice. Defaulting to Fiction.\n";
            book->Category = "Fiction";
            break;
        }

        cout << "Enter Book Price: ";
        cin >> book->Price;

        cout <<termcolor::bright_white;
        cout <<termcolor::on_bright_green;
        cout <<"Update Done\n";
        cout <<termcolor::reset;
    }
}

/**
 * Deletes a book from the library by its index, and then sorts the library.
 */

void BooksManagement::DeleteBook()
{
    if (Library.IsEmpty())
    {
        cout <<termcolor::bright_white;
        cout <<termcolor::on_bright_red;
        cout<<"\nError: The Library Is Empty At The Moment\n\n";
        cout <<termcolor::reset;
    }
    else
    {
        int Index;
        Library.PrintForward();
        cout << "\n";
        cout <<termcolor::bright_white;
        cout <<termcolor::on_bright_magenta;
        cout << "Enter Book Index: ";
        cout <<termcolor::reset;
        cin >> Index;
        cout<<endl;

        Library.DeleteNode(Index);
        cout <<termcolor::bright_white;
        cout <<termcolor::on_bright_red;
        cout << "Deleted\n";
        cout <<termcolor::reset;
    }
}

/**
 * Sorts the books in the library.
 * The books are sorted based on their title in ascending order.
 */

void BooksManagement ::SortLibrary()
{
    Library.Sort();
}

/**
 * Frees all memory used by the library by deleting all book nodes.
 */

void BooksManagement::FreeLibrary()
{
    Library.Free();
}
