find_package(Catch2 REQUIRED)

add_executable(roman_tests
  ../../testing/main.cpp
  test.cpp
)

target_link_libraries(roman_tests PUBLIC Catch2::Catch2 roman_lib)
