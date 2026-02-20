#ifndef PROPOSALS_H_
#define PROPOSALS_H_

#include "list.h"

class Proposals {
public:
  Proposals();
  Proposals &add(List list);
  int size() const;
  const List &operator[](std::size_t index) const;
  std::vector<List>::const_iterator begin() const;
  std::vector<List>::const_iterator end() const;
  Proposals &sort_by_price();

private:
  std::vector<List> proposals;
};
#endif // PROPOSALS_H_
