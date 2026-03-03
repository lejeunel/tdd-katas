#ifndef GREETING_H_
#define GREETING_H_
#include "clock.h"
#include "display.h"
#include "session.h"
#include <string>
#include <vector>

enum PhaseOfDay { morning, afternoon, evening };

struct GreetingInput {
  std::string name;
};

struct GreetingResponse {
  PhaseOfDay phase;
  std::string name;
  SessionId session_id = "";
};

class GreetingOutputPort {
public:
  virtual void present(const GreetingResponse &) = 0;
};

class SpyGreetingPresenter : public GreetingOutputPort {

public:
  SpyGreetingPresenter();
  void present(const GreetingResponse &);
  std::vector<GreetingResponse> responses;
};

class StringGreetingPresenter : public GreetingOutputPort {
public:
  StringGreetingPresenter(Display &d);
  void present(const GreetingResponse &);

private:
  Display &display;
};

class GreetingInteractor {
public:
  GreetingInteractor(SessionRepo &sr, const Clock &c);
  void greet(const GreetingInput &in, GreetingOutputPort &out);

private:
  SessionRepo &session_repo;
  PhaseOfDay get_phase();
  const Clock &clock;
};

#endif // GREETING_H_
