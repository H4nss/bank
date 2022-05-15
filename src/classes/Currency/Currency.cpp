#include "Currency.h";

const std::vector<std::string> Currency::codes {Currency::PLNcode, Currency::EURcode, Currency::USDcode, Currency::CHFcode, Currency::GBPcode};
const double PLNratio = 1;
const double EURratio = 0.21;
const double USDratio = 0.22;
const double CHFratio = 0.22;
const double GBPratio = 0.18;;
const std::string PLNcode = "PLN";
const std::string EURcode = "EUR";
const std::string USDcode = "USD";
const std::string CHFcode = "CHF";
const std::string GBPcode = "CHF";

Currency::Currency() {
  code = Currency::PLNcode;
}

Currency::Currency(std::string currencyCode){
  if(isValidInputCode(currencyCode)){
    code = currencyCode;
  }

  code = Currency::PLNcode;
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
  if (code == Currency::PLNcode) {
    return PLNratio;
  }

  if (code == Currency::EURcode) {
    return EURratio;
  }

  if (code == Currency::USDcode) {
    return USDratio;
  }

  if (code == Currency::CHFcode) {
    return CHFratio;
  }

  if (code == Currency::GBPcode) {
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
