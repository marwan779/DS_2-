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
    cout << "Enter Book Title: ";
    fflush(stdin);
    getline(cin, book.Title);

    if (Library.BookExist(book.Title))
    {
        // cout << "\nA Book With The Same Title Exists. Choice Different Title Please\n\n";
        ErrorBM = "\nA Book With The Same Title Exists. Choice Different Title Please\n\n";
    }
    else
    {
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
            // cout << "Invalid category choice. Defaulting to Fiction.\n";
            ErrorBM = "Invalid category choice. Defaulting to Fiction.\n";
            book.Category = "Fiction";
            break;
        }

        cout << "Enter Book Price: ";
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
    int Choice;
    string Category;
    cout << "1. Fiction\n2. History\n3. Mystery\n4. Science\n";
    cout << "choice Book Category: ";
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
        // cout << "Invalid category choice. Defaulting to Fiction.\n";
        ErrorBM = "Invalid category choice. Defaulting to Fiction.\n";
        Category = "Fiction";
        break;
    }

    Library.PrintByCategory(Category);
}

/**
 * Prompts the user to enter a book title and searches for it in the library.
 * If the book is found, its details are printed; otherwise, an error message is displayed.
 */

void BooksManagement::SearchForBook()
{
    if(Library.IsEmpty())
    {
        // cout<<"\nThe List Is Embty At The Moment\n\n";
        ErrorBM = "\nThe List Is Embty At The Moment\n\n";
    }
    else
    {
        string Title;
        cout << "Enter Book Title: ";
        fflush(stdin);
        getline(cin, Title);
        Book Temp = Library.Search(Title);
        if (Temp.Title == "")
        {
            // cout << "\nNo Book With Such Name\n\n";
            ErrorBM = "\nNo Book With Such Name\n\n";
        }
        else
        {
            Library.PrintBook(Temp);
        }
    }
}

/**
 * Deletes a book from the library and then prompts the user to enter new book details to update it.
 */

void BooksManagement::UpdateBook()
{
    DeleteBook();
    cout << "\nEnter New Data\n";
    AddBookTolibrary();
}

/**
 * Deletes a book from the library by its index, and then sorts the library.
 */

void BooksManagement::DeleteBook()
{
    int Index;
    Library.PrintForward();
    cout << "\n";
    cout << "Entere Book Index: ";
    cin >> Index;

    Library.DeleteNode(Index);
    Library.Sort();
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
