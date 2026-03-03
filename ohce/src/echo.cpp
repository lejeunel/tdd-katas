#include "include/echo.h"
#include "include/exceptions.h"
#include <format>

StringEchoPresenter::StringEchoPresenter(Display &d) : display(d) {};

void StringEchoPresenter::present(const EchoResponse &r) {
  display.insert(std::format("> {}", r.message));
};

SpyEchoPresenter::SpyEchoPresenter() {};
void SpyEchoPresenter::present(const EchoResponse &r) {
  responses.push_back(r);
};

EchoInteractor::EchoInteractor(SessionRepo &r) : session_repo(r) {};

void EchoInteractor::interact(const EchoInput &in, EchoOutputPort &out) const {

  if (!session_repo.id_exists(in.session_id))
    throw SessionNotFoundException();

  if (in.message == "Stop!") {
    session_repo.remove(in.session_id);
    out.present(EchoResponse{.message = "See you later!"});
    return;
  }
  std::string reversed(in.message.rbegin(), in.message.rend());
  out.present(EchoResponse{.message = reversed});
};
