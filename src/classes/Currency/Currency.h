#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <vector>

class Currency {
  static const std::vector<std::string> codes;

  static double getCurrencyRatio(std::string code);
  static double getCurrencyConvertRatio(std::string currencyCodeFrom, std::string currencyCodeTo);

  static const double PLNratio;
  static const double EURratio;
  static const double USDratio;
  static const double CHFratio;
  static const double GBPratio;
  static const std::string PLNcode;
  static const std::string EURcode;
  static const std::string USDcode;
  static const std::string CHFcode;
  static const std::string GBPcode;

  bool isValidInputCode(std::string inputCode);
  std::string code;
  double ratio;

public:
  Currency() = default;
  Currency(std::string currencyCode);
  Currency& operator=(const Currency& _c) {
    return *this;
  }

  std::string getCode();
  double getRatio();
  double getCurrencyConvertRatioTo(std::string currencyCodeTo);
};

#endif
