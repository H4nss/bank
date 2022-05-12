#include <iostream>
#include <string>
#include<fstream>
#include<iomanip>
#include <conio.h>

#ifndef FOREIGNCURRECY_h
#define FOREIGNCURRECY_h

using namespace std;


class Foreigncurrency
{
public:
    double sumPLN = 0, sumEUR = 0, sumUSD = 0, sumCHF = 0; //suma pieniedzy w poszczegolnych walutach
    char firstChoice, secondChoice; //wybor walut do zamiany
    string firstCurrency, secondCurrency; //wyswietlanie nazw walut w opisach
    double a = 0, b = 0;
    char firstSign;
    long double balance = 0;

    void choice(); // wybor opcji w menu Konta Walutowego
    void changePLN(); //zamiana z waluty PLN-->x
    void changeEUR(); //zamiana z waluty EUR-->x
    void changeUSD(); //zamiana z waluty USD-->x
    void changeCHF(); //zamiana z waluty CHF-->x
    void foreignCurrency(); //Konto Walutowe
    void menuForeignCurrency(); //Menu Konta Walutowego

};
#endif