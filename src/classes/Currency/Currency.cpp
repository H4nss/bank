#include "Currency.h";

const std::vector<std::string> Currency::codes {"PLN", "EUR", "USD", "CHF", "GBP"};
const double PLNratio = 1;
const double EURratio = 0.21;
const double USDratio = 0.22;
const double CHFratio = 0.22;
const double GBPratio = 0.18;

Currency::Currency() {
  code = "PLN";
}

Currency::Currency(std::string currencyCode){
  if(isValidInputCode(currencyCode)){
    code = currencyCode;
  }

  code = "PLN";
  ratio = Currency::getCurrencyRatio(currencyCode);
}

std::string Currency::getCode() {
  return code;
}

double Currency::getRatio() {
  return ratio;
}

bool Currency::isValidInputCode(std::string code) {
  if(std::find(codes.begin(), codes.end(), code) != codes.end()) {
    return true;
  }

  return false;
}

double Currency::getCurrencyRatio(std::string code) {
  if (code == "PLN") {
    return PLNratio;
  }

  if (code == "EUR") {
    return EURratio;
  }

  if (code == "USD") {
    return USDratio;
  }

  if (code == "CHF") {
    return CHFratio;
  }

  if (code == "GBP") {
    return GBPratio;
  }

  return -1;
}

double Currency::getCurrencyConvertRatio(std::string currencyCodeFrom, std::string currencyCodeTo) {
  double currencyFromRatio = getCurrencyRatio(currencyCodeFrom);
  double currencyToRatio = getCurrencyRatio(currencyCodeTo);

  return currencyToRatio / currencyFromRatio;
}

double Currency::getCurrencyConvertRatioTo(std::string currencyCodeTo) {
  double currencyToRatio = getCurrencyRatio(currencyCodeTo);

  return std::floor(currencyToRatio / ratio);
}
