#ifndef WARDROBE_CATALOG_H_
#define WARDROBE_CATALOG_H_
#include "wardrobe.h"
#include <vector>

using WardrobeList = std::vector<Wardrobe>;
using WardrobeCombinations = std::vector<WardrobeList>;

class WardrobeCatalog {
  public:
    WardrobeCatalog();
    WardrobeCombinations combinations(int wall_size);
    void add(const Wardrobe &wr);

  private:
    WardrobeList wardrobes;
};

#endif // WARDROBE_CATALOG_H_
