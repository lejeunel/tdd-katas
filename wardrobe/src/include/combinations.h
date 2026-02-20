#ifndef COMBINATIONS_H_
#define COMBINATIONS_H_

#include "list.h"

class Combinations {
public:
  Combinations();
  void add(const List &list);
  int size() const;
  const List &operator[](std::size_t index) const;
  std::vector<List>::const_iterator begin() const;
  std::vector<List>::const_iterator end() const;
  bool contains(const List &list);

private:
  std::vector<List> combinations;
};
#endif // COMBINATIONS_H_
