find_package(Catch2 REQUIRED)

add_executable(test
  main.cpp
  test.cpp
)

target_link_libraries(test PUBLIC Catch2::Catch2 xmas-lights)
