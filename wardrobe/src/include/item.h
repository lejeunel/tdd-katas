#ifndef ITEM_H_
#define ITEM_H_

#include <string>

class Item {
public:
  Item(const std::string &name, const int &size);
  const int &size() const;
  const std::string &name() const;
  bool operator==(const Item &other) const;

private:
  int _size;
  std::string _name;
};

#endif // ITEM_H_
