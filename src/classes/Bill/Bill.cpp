#include "Bill.h";
#include "Currency.h";

Bill::Bill(double newValue, Currency newCurrency) {
  balance = newValue;
  currency = newCurrency;
}

double Bill::getBalance() {
  return balance;
}

std::string Bill::getBalanceWithCurrency() {
  return std::to_string(balance) + " " + currency.code;
}

std::string Bill::getCurrencyType() {
  return currency.code;
}

double Bill::deposit(double amount) {
  if (amount <= 0) {
    return -1;
  }

  balance += amount;

  return balance;
}

double Bill::withdraw(double amount) {
  if (amount <= 0 || balance - amount < 0) {
    return -1;
  }

  balance -= amount;

  return balance;
}

double Bill::getConvertedTo(Currency currencyTo) {
  std::string currencyCodeTo = currencyTo.code;

  double convertRatio = currency.getCurrencyConvertRatio(currency.code, currencyCodeTo);


  return balance * convertRatio;
}
