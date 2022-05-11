#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <vector>

class Currency {
  static const std::vector<std::string> codes;

  const double PLN = 1;
  const double EUR = 0.21;
  const double USD = 0.22;
  const double CHF = 0.22;
  const double GBP = 0.18;

  bool validInputCode(std::string inputCode);
  double getCurrencyRatio(std::string code);
public:
  std::string code;

  Currency() = default;
  Currency(std::string currencyCode);
  Currency& operator=(const Currency& _c) {
    return *this;
  }
  double getCurrencyConvertRatio(std::string currencyCodeFrom, std::string currencyCodeTo);
};

#endif
