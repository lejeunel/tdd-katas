find_package(Catch2 REQUIRED)

add_executable(wardrobe_tests
  ../../testing/main.cpp
  test.cpp
)

# target_link_libraries(xmas_lights_tests PUBLIC Catch2::Catch2 xmas_lights_lib)
target_link_libraries(wardrobe_tests PUBLIC Catch2::Catch2 wardrobe_lib)
