#include <iostream>

using namespace std;

class Book
{
public:
    Book()
    {
    }

    const string & name()
    {
        return _name;
    }

    void  setName(const string &newName)
    {
        _name = newName;
    }

private:
    string  _name;
};

class BookStore
{
public:
    BookStore()
    {
    }

    void  AddBook(Book *book)
    {
        if (count < 20)
        {
            _books[count] = *book;
            count++;
        }
        else
        {
            return;
        }
    }

    void  searchByName(string name)
    {
        for (auto i : _books)
        {
            if (i.name() == name)
            {
                cout << "congratulations!\nwe have " << name << " book" << endl;

                return;
            }
            else
            {
                cout << "Sorry , Your book was not found :) " << endl;

                return;
            }
        }
    }

private:
    Book  _books[20];
    int   count { 0 };
};


class Menu
{
public:
    enum MenuItems
    {
        AddBook      = 1,
        SearchByName = 2,
        Exit         = 3
    };

    Menu()
    {
        _store = new BookStore;
    }

    ~Menu()
    {
        delete _store;
    }

    void  show()
    {
        cout << "Choose one of this options : " << endl;

        cout << "1 . AddBook :  " << endl;

        cout << "2 . SearchByName : " << endl;

        cout << "3 . Exit  " << endl;

        cin >> userSelect;

        switch (userSelect)
        {
        case AddBook:
        {
            string  bookname = "";
            cout << "Enter your book name : " << endl;
            cin >> bookname;

            Book *_book = new Book();
            _book->setName(bookname);
            _store->AddBook(_book);

            cout << "congratulations!\nYour book has been added." << endl;
            break;
        }

        case SearchByName:
        {
            string  bookname = "";
            cout << "Enter your book name : " << endl;
            cin >> bookname;
            _store->searchByName(bookname);

            break;
        }
        case Exit:
        {
            exit(0);
            break;
        }
        default:
            break;
        }
    }

    int  getUserSelect()
    {
        return userSelect;
    }

private:
    int        userSelect { 1 };
    BookStore *_store;
};

int  main()
{
    Menu *_menu = new Menu;

    while (_menu->getUserSelect() != 3)
    {
        _menu->show();
    }

    return 0;
}
