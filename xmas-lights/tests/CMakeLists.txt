find_package(Catch2 REQUIRED)

add_executable(xmas_lights_tests
  ../../testing/main.cpp
  test_regions.cpp
  test_grid.cpp
  test_activate.cpp
  test_disactivate.cpp
  test_toggle.cpp
)

target_link_libraries(xmas_lights_tests PUBLIC Catch2::Catch2 xmas_lights_lib)
