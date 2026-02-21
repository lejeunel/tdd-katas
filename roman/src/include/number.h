#ifndef NUMBER_H_
#define NUMBER_H_
#include <array>
#include <string>
#include <unordered_map>
class Number {
public:
  Number(int);
  std::string to_roman() const;
  inline static const std::array<int, 7> bases = {1000, 500, 100, 50, 10, 5, 1};
  inline static const std::unordered_map<int, std::string> mapping = {
      {1, "I"},   {5, "V"},   {10, "X"},  {50, "L"},
      {100, "C"}, {500, "D"}, {1000, "M"}};

private:
  int number;
};

#endif // NUMBER_H_
