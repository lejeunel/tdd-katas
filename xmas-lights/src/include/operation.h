#ifndef OPERATION_H_
#define OPERATION_H_

#include "region.h"

class Operation {
  public:
    Operation(const Region &a_region);
    bool operator==(const Operation &other) const;
    const Region &get_region() const;

  private:
    Region region;
};

#endif // OPERATION_H_
