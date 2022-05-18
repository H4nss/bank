#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <vector>

#include "Bank.hpp"
#include "PiggyBank.hpp"
#include "User.hpp"

class Interface
    : virtual private User,
      Bank,
      PiggyBank
{
public:
  void displayWelcomeScreen();

private:
  void displayMainScreen();
  void displayHeader();
  void displayExitScreen();
  void loginScreen();
  void registerScreen();
  void successDepositOrWithdrawScreen(long double money, std::string currency, short n);
  void depositScreen();
  void withdrawScreen();
  void transferScreen();
  void transferListScreen();
  void changeCurrencyScreen();
};

#endif