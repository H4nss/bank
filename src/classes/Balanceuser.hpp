#ifndef Balanceuser_hpp
#define Balanceuser_hpp

#include <string>
#include "Database.hpp"

class Balanceuser
{
public:
    long double getBalance(const std::string username, bool isAuthorized);
};

#endif