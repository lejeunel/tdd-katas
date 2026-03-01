#include "include/display.h"

void FakeDisplay::render() {}

void FakeDisplay::insert(const std::string &message) {
  lines_.push_back(message);
}
