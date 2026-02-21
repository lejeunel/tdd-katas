#include "include/number.h"
#include <format>
#include <stdexcept>
#include <string>

Number::Number(int a_number) : number(a_number) {};

std::string Number::to_roman() const {
  if (number < 1)
    throw std::invalid_argument(std::format(
        "Number to convert should be greater than 0, got {}", number));

  auto remainder = number;
  std::string result = "";
  for (const int base : Number::bases) {
    if (remainder == 0)
      break;
    std::string base_str = mapping.at(base);
    if (remainder / base > 0) {
      result.append(remainder / base, base_str[0]);
      remainder -= remainder / base * base;
      continue;
    }
    if ((remainder + 1) == base) {
      result.append("I" + base_str);
      remainder -= base - 1;
    }
  }
  return result;
}
