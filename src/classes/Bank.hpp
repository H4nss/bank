#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <vector>

#include "User.hpp"

class Bank : virtual private User
{
public:
    double ammountToChange = 0, converted = 0;           // zmienne sluzace przy zamianie walut
    void changePLN(char firstChoice, char secondChoice); // zamiana z waluty PLN-->x
    void changeEUR(char firstChoice, char secondChoice); // zamiana z waluty EUR-->x
    void changeUSD(char firstChoice, char secondChoice); // zamiana z waluty USD-->x
    void changeCHF(char firstChoice, char secondChoice); // zamiana z waluty CHF-->x
    void changeGBP(char firstChoice, char secondChoice); // zamiana z waluty GBP-->x
};

#endif