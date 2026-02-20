#include "include/item.h"

Item::Item(const std::string &a_name, const int &a_size)
    : _size(a_size), _name(a_name) {}

Item::Item(const std::string &a_name, const int &a_size, const float &a_price)
    : _size(a_size), _name(a_name), _price(a_price) {}

const int &Item::size() const { return _size; }
const std::string &Item::name() const { return _name; }
const float &Item::price() const { return _price; }
bool Item::operator==(const Item &other) const { return _name == other.name(); }
