#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <fstream>
#include <iostream>

class User
{
public:
    bool doesUserExist(std::string username, std::string password);
    std::string getLineFromFile(const std::string username, short n);
    bool deposit(long double n, short currency);
    void read();
    long double PLN = 0, EUR = 0, USD = 0, CHF = 0, GBP = 0; // suma pieniedzy w poszczegolnych walutach
    long double piggyAccount = 0;                            // suma pieniedzy w Skarbonce
    std::string name;
    bool RegisterUser(std::string username, std::string password);
    bool withdraw(long double n, short currency);
    long double moneyChanger(long double n, short currencyO, short currencyS);
    short Transfer(long double n, short currency, std::string username);
    bool raportTransfer(long double n, short currency, std::string username);
    void raportTransferRead();
};

#endif
