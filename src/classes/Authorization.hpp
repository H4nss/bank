// Sprawdza czy podany login i hasło jest prawidłowe
#ifndef Authorization_hpp
#define Authorization_hpp

#include <string>
#include "Database.hpp"

using namespace std;

class Authorization
{
public:
    bool doesUserExist(string username, string password);
};

#endif