#ifndef PIGGYBANK_HPP
#define PIGGYBANK_HPP

#include <functional>

#include "User.hpp"

class PiggyBank : virtual private User
{
public:
  void displayMenu();            // Menu Skarbonki
  void displayOptions();         // Skarbonka
  char option;                   // zmienna odpowiadajace za opcje w Skarbonce
  long double getMainBallance(); // zwraca saldo w skarbonce

private:
  void displayInfo();
};

#endif