#include "include/exceptions.h"

StoppedSessionException::StoppedSessionException() {};

const char *StoppedSessionException::what() const noexcept {
  return "session is stopped";
}

SessionNotFoundException::SessionNotFoundException() {};

const char *SessionNotFoundException::what() const noexcept {
  return "session does not exist";
}
