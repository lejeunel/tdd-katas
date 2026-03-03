#include "../src/include/display.h"
#include "../src/include/echo.h"
#include "../src/include/exceptions.h"
#include "../src/include/session.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("echo a string", "[echo-a-string]") {
  auto display = FakeDisplay();
  auto presenter = StringEchoPresenter(display);
  EchoResponse r = {.message = "a string"};
  presenter.present(r);
  REQUIRE(display.content().back() == "> a string");
}

TEST_CASE("echo string with invalid session", "[echo-invalid-session]") {
  auto id = SessionId{"invalid-id"};
  auto in = EchoInput{.session_id = id, .message = "hi!"};
  auto out = SpyEchoPresenter();
  auto sr = TestingSessionRepo();
  auto interactor = EchoInteractor(sr);
  REQUIRE_THROWS_AS(interactor.interact(in, out), SessionNotFoundException);
}

TEST_CASE("echo string with valid session", "[echo-valid-session]") {
  auto id = SessionId{"valid-id"};
  auto in = EchoInput{.session_id = id, .message = "hi!"};
  auto out = SpyEchoPresenter();
  auto sr = TestingSessionRepo();
  sr.add(id);
  auto interactor = EchoInteractor(sr);
  interactor.interact(in, out);
  REQUIRE(out.responses[0].message == "!ih");
}

TEST_CASE("echo string to a stopped session should fail",
          "[echo-stopped-session]") {
  auto id = SessionId{"my-id"};
  auto sr = TestingSessionRepo();
  sr.add(id);

  auto out = SpyEchoPresenter();
  auto interactor = EchoInteractor(sr);
  interactor.interact(EchoInput{.session_id = id, .message = "Stop!"}, out);
  REQUIRE(out.responses.size() == 1);

  auto in = EchoInput{.session_id = id, .message = "something"};
  REQUIRE_THROWS_AS(interactor.interact(in, out), SessionNotFoundException);
}
