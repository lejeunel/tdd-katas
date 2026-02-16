add_library(xmas-lights
  grid.cpp
)
add_executable(xmas-lights-bin
  main.cpp)

target_link_libraries(xmas-lights-bin xmas-lights)

install(TARGETS xmas-lights-bin
  RUNTIME DESTINATION bin
)
