#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <fstream>
#include <iostream>

class User
{
public:
    class Database
    {
    public:
        std::string getLineFromFile(const std::string username, short targetLineNumber);
        bool saveTransferToFile(long double ammount, short currency, std::string currentUsername, std::string targetUsername);
    };

    Database db;
    std::string name;
    long double PLN = 0, EUR = 0, USD = 0, CHF = 0, GBP = 0, piggyAccount = 0;

    virtual long double getMainBallance() = 0; // zwraca saldo w złotówkach i jest czystą funkcją wirtualna

    bool doesUserExist(std::string username, std::string password);
    bool deposit(long double n, short currency);

    bool RegisterUser(std::string username, std::string password);
    bool withdraw(long double n, short currency);
    short Transfer(long double n, short currency, std::string username);
    void raportTransferRead();
};

#endif
