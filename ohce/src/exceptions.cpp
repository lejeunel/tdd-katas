#include "include/exceptions.h"

InteractOnStoppedSessionException::InteractOnStoppedSessionException() {};

const char *InteractOnStoppedSessionException::what() const noexcept {
  return "InteractOnStoppedSessionException occured";
}
