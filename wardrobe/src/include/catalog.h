#ifndef CATALOG_H_
#define CATALOG_H_
#include "item.h"
#include "list.h"
#include "proposals.h"

class Catalog {
public:
  Catalog();
  Proposals propose(const int &wall_size);
  void add(const Item &wr);

private:
  List items;
  void find_proposals(Proposals &proposals, List &list, int wall_size,
                      std::size_t start_ix);
};

#endif
