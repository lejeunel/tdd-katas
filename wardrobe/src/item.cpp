#include "include/item.h"

Item::Item(const std::string &a_name, const int &a_size)
    : _size(a_size), _name(a_name) {}

const int &Item::size() const { return _size; }
const std::string &Item::name() const { return _name; }
bool Item::operator==(const Item &other) const { return _name == other.name(); }
