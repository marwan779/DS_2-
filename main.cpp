#include <iostream>
#include "termcolor.hpp"
#include "BooksManagement.cpp"
#include <limits>

using namespace std;

int main()
{
    BooksManagement BM;
    int Choice1 = 1, Choice2;
    cout << termcolor::bright_white;
    cout << "***********************************************\n";
    cout << "  Library Management System  Colored version\t";
    // for RGB logo
    cout << termcolor::bright_red;
    cout << termcolor::on_bright_red;
    cout << "RC";
    cout << termcolor::bright_green;
    cout << termcolor::on_bright_green;
    cout << "GC";
    cout << termcolor::bright_blue;
    cout << termcolor::on_bright_blue;

    cout << "BC";
    cout << termcolor::reset;
    cout << "    Main Menu";
    cout << endl;
    cout << termcolor::bright_white;
    cout << "***********************************************\n";
    cout << termcolor::reset;

    while (1)
    {
        if (Choice1 == 1)
        {
            cout << "\n";
            // cout <<termcolor::on_bright_white;
            cout << termcolor::bright_green;
            cout << "[1] Add Book To The Library.\n";
            cout << termcolor::bright_magenta;
            cout << "[2] Print All The Books In The Library.\n";
            cout << "[3] Print All The Books By Category.\n";
            cout << termcolor::bright_blue;
            cout << "[4] Search For Book.\n";
            cout << termcolor::yellow;
            cout << "[5] Update Book.\n";
            cout << termcolor::bright_red;
            cout << "[6] Delete Book.\n";
            cout << termcolor::cyan;
            cout << "[7] Sort The Library.\n";
            cout << termcolor::bright_red;
            cout << "[8] Free The Library.\n";
            cout << termcolor::reset;
            cout << "Enter Your Choice: ";

            cin >> Choice2;
            while (cin.fail())
            {
                cout << termcolor::on_bright_red;
                cout << termcolor::bright_white;
                cout << "Please enter a valid number!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << termcolor::reset;
                cout << "Enter Your Choice: ";
                cin >> Choice2;
            }
            switch (Choice2)
            {
            case 1:
                BM.AddBookTolibrary();
                break;
            case 2:
                BM.PrintBooks();
                break;
            case 3:
                BM.PrintByCategory();
                break;
            case 4:
                BM.SearchForBook();
                break;
            case 5:
                BM.UpdateBook();
                break;
            case 6:
                BM.DeleteBook();
                break;
            case 7:
                BM.SortLibrary();
                break;
            case 8:
                BM.FreeLibrary();
                break;
            default:
                break;
            }
        }
        else if (Choice1 == 2)
        {
            break;
        }
        else
        {
            cout << termcolor::on_bright_red;
            cout << termcolor::bright_white;
            cout << "Error: Enter a vaild choice\n";
            cout << termcolor::reset;
        }

        cout << termcolor::bright_green;
        cout << "1. Continue\n";
        cout << termcolor::bright_red;
        cout << "2. Exit\n";
        cout << termcolor::bright_white;
        cout << "Enter Your Choice: ";
        cin >> Choice1;

        while (cin.fail())
        {
            cout << termcolor::on_bright_red;
            cout << termcolor::bright_white;
            cout << "Please enter a valid number!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << termcolor::reset;
            cout << "Enter Your Choice: ";
            cin >> Choice1;
        }
    }
}