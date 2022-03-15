// Sprawdza czy podany login i hasło jest prawidłowe
#include <iostream>
#include <string>
#include <fstream>

#ifndef authorization_hpp
#define authorization_hpp

using namespace std;

class authorization
{
public:
    bool IsUserExist(string username, string password);
};

bool authorization::IsUserExist(string username, string password)
{
    string fileName = username + ".dat";
    string path = "data\\" + fileName;
    fstream plik(path, std::ios::in); // zakładamy, że plik istnieje
    string passwordinfile;
    getline(plik, passwordinfile);
    plik.close();
    if (ifstream(path) && password == passwordinfile)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
#endif