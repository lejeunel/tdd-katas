#ifndef ITEM_H_
#define ITEM_H_

#include <string>

class Item {
public:
  Item(const std::string &name, const int &size);
  Item(const std::string &name, const int &size, const float &price);
  const int &size() const;
  const std::string &name() const;
  const float &price() const;
  bool operator==(const Item &other) const;

private:
  int _size;
  std::string _name;
  float _price;
};

#endif // ITEM_H_
