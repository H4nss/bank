#ifndef BILL_H
#define BILL_H

#include <string>
#include "Currency.h";

class Bill {
  double balance;
  Currency currency;

public:
  Bill(double amount, Currency newCurrency);
  double getBalance();
  std::string getBalanceWithCurrency();
  std::string getCurrencyType();
  double deposit(double amount);
  double withdraw(double amount);

  double getConvertedTo(Currency currencyTo);
};

#endif
