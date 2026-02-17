#include "include/operation.h"

Operation::Operation(const Region &a_region) : region(a_region) {}

bool Operation::operator==(const Operation &other) const {
  return region == other.region;
};

const Region &Operation::get_region() const { return region; }
