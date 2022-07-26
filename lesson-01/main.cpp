#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int  main()
{
    bool  running = true;
    int   choise  = 0;

    while (running)
    {
        cout << "\tMAIN MENU \n";
        cout << "1.Register user" << endl;
        cout << "2.Login user" << endl;
        cout << "3.Exit" << endl;
        cin >> choise;

        switch (choise)
        {
        case 01:
        {
            string  username;
            string  password;
            cout << "Enter username : ";
            cin >> username;
            cout << "Enter password : ";
            cin >> password;

            ofstream  file;
            file.open("users.txt");

            file << username << endl;
            file << password << endl;

            file.close();
        }
        break;
        case 02:
        {
            string  iUsername;
            string  iPassword;
            string  fUsername;
            string  fPassword;

            cout << "Username : ";
            cin >> iUsername;
            cout << "Password : ";
            cin >> iPassword;

            ifstream  file;
            file.open("users.txt");

            if (file.is_open())
            {
                getline(file, fUsername);
                getline(file, fPassword);

                if ((fUsername == iUsername) && (fPassword == iPassword))
                {
                    std::cout << "User login ok." << endl;
                }
                else
                {
                    std::cout << "User login failed." << endl;
                }
            }
            else
            {
                std::cout << "Can't find user.txt." << std::endl;
            }
        }
        break;
        case 03:
            running = false;
            break;
        default:
            cout << "Choise from menu. " << endl;
            break;
        }
    }

    return 0;
}
