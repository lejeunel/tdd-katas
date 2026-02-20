find_package(Catch2 REQUIRED)

add_executable(manhattan_tests
  ../../testing/main.cpp
  test.cpp
)

target_link_libraries(manhattan_tests PUBLIC Catch2::Catch2 manhattan_lib)
