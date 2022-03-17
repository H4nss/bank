#include "Balanceuser.hpp"

long double Balanceuser::getBalance(const std::string username, bool isAuthorized)
{
    if (isAuthorized)
    {
        Database Database;
        return std::stold(Database.getLineFromFile(username, 1));
    }
    return 0;
};