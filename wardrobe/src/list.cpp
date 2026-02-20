#include "include/list.h"
#include <format>
#include <string>
#include <unordered_map>

List::List() {};

std::size_t List::size() const { return items.size(); };

const Item &List::operator[](std::size_t index) const { return items[index]; };

List &List::add(Item item) {
  items.push_back(item);
  return *this;
}

List &List::pop() {
  items.pop_back();
  return *this;
}

int List::length() const {
  auto length = 0;
  for (const auto &w : items)
    length += w.size();
  return length;
}

bool List::operator==(const List &other) const {
  if (items.size() != other.items.size())
    return false;

  std::unordered_map<std::string, int> counts;

  for (const auto &w : items)
    counts[w.name()]++;
  for (const auto &w : other.items)
    counts[w.name()]--;

  for (const auto &[name, count] : counts)
    if (count != 0)
      return false;

  return true;
}

std::vector<Item>::const_iterator List::begin() const { return items.begin(); }
std::vector<Item>::const_iterator List::end() const { return items.end(); }

std::ostream &operator<<(std::ostream &os, const List &list) {
  for (const auto &w : list)
    os << std::format("{} / ", w.name());
  return os;
}

float List::price() const {
  float result = 0.;
  for (const auto &i : items)
    result += i.price();
  return result;
}
