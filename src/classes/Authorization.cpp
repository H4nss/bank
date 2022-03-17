#include "Authorization.hpp"

bool Authorization::doesUserExist(string username, string password)
{
    Database Database;
    std::string passwordinfile = Database.getLineFromFile(username, 0);

    if (password == passwordinfile)
    {
        return 1;
    }
    return 0;
}