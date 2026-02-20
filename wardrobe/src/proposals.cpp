#include "include/proposals.h"
#include <algorithm>

Proposals::Proposals() {};
Proposals &Proposals::add(List list) {
  proposals.push_back(std::move(list));
  return *this;
}

const List &Proposals::operator[](std::size_t index) const {
  return proposals[index];
}

int Proposals::size() const { return proposals.size(); }

std::vector<List>::const_iterator Proposals::begin() const {
  return proposals.begin();
}
std::vector<List>::const_iterator Proposals::end() const {
  return proposals.end();
}

Proposals &Proposals::sort_by_price() {
  std::sort(proposals.begin(), proposals.end(),
            [](const List &a, const List &b) { return a.price() < b.price(); });
  return *this;
}
