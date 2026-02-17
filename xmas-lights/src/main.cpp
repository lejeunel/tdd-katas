#include "include/grid.h"
#include <iostream>

auto main() -> int {

  auto grid = Grid(1000, 1000);

  // turn on 887,9 through 959,629
  grid.activate_region(Region{887, 957, 9, 629});
  // turn on 454,398 through 844,448
  grid.activate_region(Region{454, 844, 398, 448});
  // turn off 539,243 through 559,965
  grid.disactivate_region(Region{539, 559, 243, 965});
  // turn off 370,819 through 676,868
  grid.disactivate_region(Region{370, 676, 819, 868});
  // turn off 145,40 through 370,997
  grid.disactivate_region(Region{145, 370, 40, 997});
  // turn off 301,3 through 808,453
  grid.disactivate_region(Region{301, 808, 3, 453});
  // turn on 351,678 through 951,908
  grid.activate_region(Region{351, 951, 678, 908});
  // toggle 720,196 through 897,994
  grid.toggle_region(Region{720, 897, 196, 994});
  // toggle 831,394 through 904,860
  grid.toggle_region(Region{831, 904, 394, 960});

  std::cout << "light emission: " << grid.light_emission() << std::endl;

  return 0;
}
