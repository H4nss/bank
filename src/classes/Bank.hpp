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
    void TransferListScreen();

    void menuPiggyBank(); //Menu Skarbonki
    void piggyBank(); //Skarbonka
    void changePLN(); //zamiana z waluty PLN-->x
    void changeEUR(); //zamiana z waluty EUR-->x
    void changeUSD(); //zamiana z waluty USD-->x
    void changeCHF(); //zamiana z waluty CHF-->x
    void changeGBP(); //zamiana z waluty GBP-->x
    void foreignCurrency(); //Konto Walutowe
    void menuForeignCurrency(); //Menu Konta Walutowego

    char sign, firstSign; //zmienne odpowiadajace za opcje w Skarbonce i Koncie Walutowym
    double option2 = 0, option3 = 0; //zmienne sluzace przy zamianie walut
    char firstChoice, secondChoice; //wybor walut do zamiany
    std::string firstCurrency, secondCurrency; //wyswietlanie nazw walut w opisach

private:
    User User;
};

#endif