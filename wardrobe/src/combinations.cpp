#include "include/combinations.h"

Combinations::Combinations() {};
void Combinations::add(const List &list) { combinations.push_back(list); }

const List &Combinations::operator[](std::size_t index) const {
  return combinations[index];
}

int Combinations::size() const { return combinations.size(); }

std::vector<List>::const_iterator Combinations::begin() const {
  return combinations.begin();
}
std::vector<List>::const_iterator Combinations::end() const {
  return combinations.end();
}

bool Combinations::contains(const List &list) {
  for (const auto &l : combinations)
    if (l == list)
      return true;
  return false;
}
