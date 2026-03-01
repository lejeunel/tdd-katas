#ifndef OHCE_H_
#define OHCE_H_

#include "clock.h"
#include "display.h"
#include "session.h"
#include <string>

class Ohce {
public:
  Ohce(Display &display, const Clock &clock);
  Session start(const std::string &);
  void say(Session &session, const std::string &);

private:
  Display &display;
  const Clock &clock;
};

#endif // OHCE_H_
