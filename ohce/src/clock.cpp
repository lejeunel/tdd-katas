#include "include/clock.h"

FakeClock::FakeClock(const int a_hour) : hour(a_hour) {};

std::time_t FakeClock::now() const {
  // Start from today's local date
  std::time_t now = std::time(nullptr);
  std::tm t = *std::localtime(&now);

  // Override the time fields
  t.tm_hour = hour;
  t.tm_min = 0;
  t.tm_sec = 0;

  return std::mktime(&t);
}
