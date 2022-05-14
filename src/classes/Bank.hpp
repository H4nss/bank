#ifndef Bank_hpp
#define Bank_hpp
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <vector>
class Bank
{
public:
    void welcomeScreen();
    void mainBankScreen();
    void header(); // Wyswietla Logo
    void loginScreen();
    void exitScreen();
    void piggyBankScreen();
    void depositeScreen();
    void withdrawScreen();
    void registerScreen();
    void successWithdrawDeposit(long double money, std::string currency, short n);
    void failWithdraw();
    void moneyChangerScreen();
    void transferScreen();
    void successChange(long double money, long double change, short currency);

private:
    User User;
};

#endif