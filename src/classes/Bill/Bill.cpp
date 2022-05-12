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
  return std::to_string(balance) + " " + currency.getCode();
}

std::string Bill::getCurrencyType() {
  return currency.getCode();
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
  double convertRatio = currency.getCurrencyConvertRatioTo(currencyTo.getCode());

  return balance * convertRatio;
}
