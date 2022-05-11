#include "Currency.h";

const std::vector<std::string> Currency::codes {"PLN", "EUR", "USD", "CHF", "GBP"};

Currency::Currency() {
  code = "PLN";
}

Currency::Currency(std::string currencyCode){
  if(validInputCode(currencyCode)){
    code = currencyCode;
  }

  code = "PLN";
}

bool Currency::validInputCode(std::string code) {
  if(std::find(codes.begin(), codes.end(), code) != codes.end()) {
    return true;
  }

  return false;
}

double Currency::getCurrencyRatio(std::string code) {
  if (code == "PLN") {
    return PLN;
  }

  if (code == "EUR") {
    return EUR;
  }

  if (code == "USD") {
    return USD;
  }

  if (code == "CHF") {
    return CHF;
  }

  if (code == "GBP") {
    return GBP;
  }

  return -1;
}

double Currency::getCurrencyConvertRatio(std::string currencyCodeFrom, std::string currencyCodeTo) {
  double currencyFromRatio = getCurrencyRatio(currencyCodeFrom);
  double currencyToRatio = getCurrencyRatio(currencyCodeTo);

  return std::floor(currencyToRatio / currencyFromRatio);
}
