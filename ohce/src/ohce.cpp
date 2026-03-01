#include "include/ohce.h"
#include "include/clock.h"
#include "include/exceptions.h"
#include <format>
#include <stdexcept>

Ohce::Ohce(Display &a_display, const Clock &a_clock)
    : display(a_display), clock(a_clock) {};

Session Ohce::start(const std::string &username) {
  if (username.size() == 0)
    throw std::invalid_argument("Username should be non-empty {}");

  auto now = clock.now();
  auto local = std::localtime(&now);
  auto hour = local->tm_hour;
  if (hour >= 6 && hour < 12) {
    display.insert(std::format("> Good morning, {}!", username));
  } else if (hour >= 12 && hour < 20) {
    display.insert(std::format("> Good afternoon, {}!", username));
  } else {
    display.insert(std::format("> Good night, {}!", username));
  }
  return Session(username);
};

void Ohce::say(Session &session, const std::string &message) {
  if (session.is_stopped())
    throw InteractOnStoppedSessionException();
  if (message == "Stop!") {
    display.insert(std::format("> Good bye, {}!", session.get_username()));
    session.stop();
    return;
  }
  std::string reversed(message.rbegin(), message.rend());
  display.insert(std::format("> {}", reversed));
};
