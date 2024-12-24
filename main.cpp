#include <iostream>
#include "BooksManagement.cpp"

using namespace std;

int main()
{
    BooksManagement BM;
    int Choice1, Choice2;
    cout<<"******************************\n";
    cout<<"  Library Management System  \n";
    cout<<"******************************\n";

    cout<<"1. Continue\n2. Exit\n";
    cout<<"Enter Your Choice: ";
    cin>>Choice1;
    while(1)
    {
        if(Choice1 == 1)
        {
            cout<<"\n";
            cout<<"[1] Add Book To The Library.\n";
            cout<<"[2] Print All The Books In The Library.\n";
            cout<<"[3] Print All The Books By Category.\n";
            cout<<"[4] Search For Book.\n";
            cout<<"[5] Update Book.\n";
            cout<<"[6] Delete Book.\n";
            cout<<"[7] Sort The Library.\n";
            cout<<"[8] Free The Library.\n";
            cout<<"Enter Your Choice: ";
            cin>>Choice2;
            switch (Choice2)
            {
            case 1: BM.AddBookTolibrary();
                break;
            case 2: BM.PrintBooks();
                break;
            case 3: BM.PrintByCategory();
                break;
            case 4: BM.SearchForBook();
                break;
            case 5: BM.UpdateBook();
                break;
            case 6: BM.DeleteBook();
                break;
            case 7: BM.SortLibrary();
                break;
            case 8: BM.FreeLibrary();
                break;
            default:
                break;
            }
        }
        else if(Choice1 == 2)
        {
            break;
        }
        else
        {
            cout<<"Enter a vaild choice\n";
        }

        cout<<"1. Continue\n2. Exit\n";
        cout<<"Enter Your Choice: ";
        cin>>Choice1;

    }
}