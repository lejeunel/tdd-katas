#include "include/exceptions.h"

SessionNotFoundException::SessionNotFoundException() {};

const char *SessionNotFoundException::what() const noexcept {
  return "session does not exist";
}
