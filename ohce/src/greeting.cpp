#include "include/greeting.h"
#include "include/session.h"
#include "include/uuidv4.h"
#include <format>
#include <stdexcept>

CLIGreetingOutput::CLIGreetingOutput(Display &d) : display(d) {};
void CLIGreetingOutput::present(const GreetingResponse &r) {
  if (r.phase == PhaseOfDay::morning) {
    display.insert(std::format("> Good morning, {}!", r.name));
  } else if (r.phase == PhaseOfDay::afternoon) {
    display.insert(std::format("> Good afternoon, {}!", r.name));
  } else {
    display.insert(std::format("> Good night, {}!", r.name));
  }
};
void CLIGreetingOutput::start_session(const SessionId &id) { session_id = id; };

SpyGreetingPresenter::SpyGreetingPresenter() {};
void SpyGreetingPresenter::present(const GreetingResponse &r) {
  responses.push_back(r);
};

GreetingInteractor::GreetingInteractor(SessionRepo &s, const Clock &c)
    : session_repo(s), clock(c) {}

void GreetingInteractor::greet(const GreetingInput &in,
                               GreetingOutputPort &out) {
  if (in.name.size() == 0)
    throw std::invalid_argument("Username should be non-empty");

  auto session_id = SessionId{uuid_v4()};
  auto r = GreetingResponse{
      .phase = get_phase(), .name = in.name, .session_id = session_id};
  session_repo.add(session_id);

  out.present(r);
};

PhaseOfDay GreetingInteractor::get_phase() {
  auto now = clock.now();
  auto local = std::localtime(&now);
  auto hour = local->tm_hour;
  PhaseOfDay phase;
  if (hour >= 6 && hour < 12)
    phase = PhaseOfDay::morning;
  else if (hour >= 12 && hour < 20)
    phase = PhaseOfDay::afternoon;
  else
    phase = PhaseOfDay::evening;

  return phase;
}
