#ifndef LIST_H_
#define LIST_H_
#include "item.h"
#include <vector>

class List {
  public:
    List();
    int size() const;
    List &add(Item item);
    int length() const;

    const Item &operator[](std::size_t index) const;
    bool operator==(const List &other) const;
    std::vector<Item>::const_iterator begin() const;
    std::vector<Item>::const_iterator end() const;
    friend std::ostream &operator<<(std::ostream &os, const List &list);

  private:
    std::vector<Item> items;
};

#endif // LIST_H_
