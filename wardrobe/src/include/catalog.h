#ifndef CATALOG_H_
#define CATALOG_H_
#include "combinations.h"
#include "item.h"
#include "list.h"

class Catalog {
public:
  Catalog();
  Combinations combinations(const int &wall_size);
  void add(const Item &wr);

private:
  List items;
  void find_combinations(Combinations &combinations, List &list, int wall_size,
                         std::size_t start_ix);
};

#endif
