#include "../src/include/clock.h"
#include "../src/include/display.h"
#include "../src/include/greeting.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("greet good morning bob", "[good-morning-bob]") {
  auto display = FakeDisplay();
  auto presenter = CLIGreetingOutput(display);
  GreetingResponse r = {.phase = PhaseOfDay::morning, .name = "Bob"};
  presenter.present(r);
  REQUIRE(display.content().back() == "> Good morning, Bob!");
}

TEST_CASE("greet good morning alice", "[good-morning-alice]") {
  auto display = FakeDisplay();
  auto presenter = CLIGreetingOutput(display);
  GreetingResponse r = {.phase = PhaseOfDay::morning, .name = "Alice"};
  presenter.present(r);
  REQUIRE(display.content().back() == "> Good morning, Alice!");
}

TEST_CASE("greet good afternoon bob", "[good-afternoon-bob]") {
  auto display = FakeDisplay();
  auto presenter = CLIGreetingOutput(display);
  GreetingResponse r = {.phase = PhaseOfDay::afternoon, .name = "Bob"};
  presenter.present(r);
  REQUIRE(display.content().back() == "> Good afternoon, Bob!");
}

TEST_CASE("at 6:00 greet morning", "[at-6-greet-morning]") {
  auto out = SpyGreetingPresenter();
  auto sr = TestingSessionRepo();
  auto interactor = GreetingInteractor(sr, FakeClock(6));
  interactor.greet(GreetingInput{.name = "Bob"}, out);
  REQUIRE(out.responses[0].phase == PhaseOfDay::morning);
}

TEST_CASE("at 12:00 greet afternoon", "[at-12-greet-afternoon]") {
  auto out = SpyGreetingPresenter();
  auto sr = TestingSessionRepo();
  auto interactor = GreetingInteractor(sr, FakeClock(12));
  interactor.greet(GreetingInput{.name = "Bob"}, out);
  REQUIRE(out.responses[0].phase == PhaseOfDay::afternoon);
}

TEST_CASE("at 21:00 greet evening", "[at-21-greet-evening]") {
  auto out = SpyGreetingPresenter();
  auto sr = TestingSessionRepo();
  auto interactor = GreetingInteractor(sr, FakeClock(21));
  interactor.greet(GreetingInput{.name = "Bob"}, out);
  REQUIRE(out.responses[0].phase == PhaseOfDay::evening);
}

TEST_CASE("greeting with empty username should fail", "[empty-username]") {
  auto out = SpyGreetingPresenter();
  auto sr = TestingSessionRepo();
  auto interactor = GreetingInteractor(sr, FakeClock(0));
  REQUIRE_THROWS_AS(interactor.greet(GreetingInput{.name = ""}, out),
                    std::invalid_argument);
}

TEST_CASE("greeting adds a new session and returns the id",
          "[greeting-adds-session]") {
  auto out = SpyGreetingPresenter();
  auto sr = TestingSessionRepo();
  auto interactor = GreetingInteractor(sr, FakeClock(0));
  interactor.greet(GreetingInput{.name = "Bob"}, out);

  REQUIRE(sr.id_exists(out.responses[0].session_id));
  REQUIRE(out.responses[0].session_id != "");
}
