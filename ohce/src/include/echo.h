#ifndef ECHO_H_
#define ECHO_H_
#include "display.h"
#include "session.h"

struct EchoResponse {
  std::string message;
};

struct EchoInput {
  SessionId session_id;
  std::string message;
};

class EchoOutputPort {
public:
  virtual void present(const EchoResponse &r) = 0;
};

class StringEchoPresenter : public EchoOutputPort {
public:
  StringEchoPresenter(Display &d);
  void present(const EchoResponse &r);

private:
  Display &display;
};

class SpyEchoPresenter : public EchoOutputPort {
public:
  SpyEchoPresenter();
  void present(const EchoResponse &r);
  std::vector<EchoResponse> responses;
};

class EchoInteractor {
public:
  EchoInteractor(SessionRepo &session_repo);
  void interact(const EchoInput &in, EchoOutputPort &out) const;

private:
  SessionRepo &session_repo;
};

#endif // ECHO_H_
