find_package(Catch2 REQUIRED)

add_executable(ohce_tests
  ../../testing/main.cpp
  test_greeting.cpp
  test_echo.cpp
  test_palindrome.cpp
)

target_link_libraries(ohce_tests PUBLIC Catch2::Catch2 ohce_lib)
