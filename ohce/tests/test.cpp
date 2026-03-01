#include "../src/include/exceptions.h"
#include "../src/include/ohce.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("starting session with empty username should fail",
          "[empty-username]") {
  auto display = FakeDisplay();
  auto clock = FakeClock(0);
  auto ohce = Ohce(display, clock);
  REQUIRE_THROWS_AS(ohce.start(""), std::invalid_argument);
}

TEST_CASE("starting session at 06:00 should greet with good morning",
          "[good-morning]") {
  auto display = FakeDisplay();
  auto clock = FakeClock(6);
  auto ohce = Ohce(display, clock);
  ohce.start("Bob");
  REQUIRE(display.content().back() == "> Good morning, Bob!");
}

TEST_CASE("starting session at 13:00 should greet with good afternoon",
          "[good-afternoon]") {
  auto display = FakeDisplay();
  auto clock = FakeClock(13);
  auto ohce = Ohce(display, clock);
  ohce.start("Bob");
  REQUIRE(display.content().back() == "> Good afternoon, Bob!");
}

TEST_CASE("starting session at 22:00 should greet with good night",
          "[good-night]") {
  auto display = FakeDisplay();
  auto clock = FakeClock(22);
  auto ohce = Ohce(display, clock);
  ohce.start("Bob");
  REQUIRE(display.content().back() == "> Good night, Bob!");
}

TEST_CASE("starting session at 06:00 with other username should greet with "
          "good morning",
          "[good-morning-alice]") {
  auto display = FakeDisplay();
  auto clock = FakeClock(6);
  auto ohce = Ohce(display, clock);
  ohce.start("Alice");
  REQUIRE(display.content().back() == "> Good morning, Alice!");
}

TEST_CASE("empty string", "[empty-string]") {
  auto display = FakeDisplay();
  auto clock = FakeClock(6);
  auto ohce = Ohce(display, clock);
  auto session = ohce.start("Alice");
  ohce.say(session, "");
  REQUIRE(display.content().back() == "> ");
}

TEST_CASE("one char string", "[once-char]") {
  auto display = FakeDisplay();
  auto clock = FakeClock(6);
  auto ohce = Ohce(display, clock);
  auto session = ohce.start("Alice");
  ohce.say(session, "a");
  REQUIRE(display.content().back() == "> a");
}

TEST_CASE("two char string", "[two-chars]") {
  auto display = FakeDisplay();
  auto clock = FakeClock(6);
  auto ohce = Ohce(display, clock);
  auto session = ohce.start("Alice");
  ohce.say(session, "ab");
  REQUIRE(display.content().back() == "> ba");
}

TEST_CASE("stop token should display good bye", "[stop-display-good-bye]") {
  auto display = FakeDisplay();
  auto clock = FakeClock(6);
  auto ohce = Ohce(display, clock);
  auto session = ohce.start("Alice");
  ohce.say(session, "Stop!");
  REQUIRE(display.content().back() == "> Good bye, Alice!");
}

TEST_CASE("stopped session should throw when we say something",
          "[stopped-session-fails-on-interact]") {
  auto display = FakeDisplay();
  auto clock = FakeClock(6);
  auto ohce = Ohce(display, clock);
  auto session = ohce.start("Alice");
  ohce.say(session, "Stop!");
  REQUIRE_THROWS_AS(ohce.say(session, "hi!"),
                    InteractOnStoppedSessionException);

  REQUIRE(display.content().back() == "> Good bye, Alice!");
}
