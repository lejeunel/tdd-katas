#include "include/combinations.h"

Combinations::Combinations() {};
void Combinations::add(const List &list) { combinations.push_back(list); }

const List &Combinations::operator[](std::size_t index) const {
  return combinations[index];
}

int Combinations::size() const { return combinations.size(); }
