#ifndef WARDROBE_CATALOG_H_
#define WARDROBE_CATALOG_H_
#include <vector>

class Wardrobe {};

class WardrobeCatalog {
  public:
    WardrobeCatalog();
    std::vector<Wardrobe> combinations(int wall_size);
};

#endif // WARDROBE_CATALOG_H_
