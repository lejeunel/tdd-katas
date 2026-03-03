#include "../src/include/palindrome.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("empty string is not a palindrome", "[empty-not-palindrome]") {
  REQUIRE(SimplePalindromeDetector().detect("") == false);
}

TEST_CASE("one char string is not a palindrome", "[one-char-not-palindrome]") {
  REQUIRE(SimplePalindromeDetector().detect("a") == false);
}

TEST_CASE("three char strings is palindrome", "[three-char-is-palindrome]") {
  REQUIRE(SimplePalindromeDetector().detect("aba") == true);
}

TEST_CASE("echo reversed string without congrats",
          "[echo-reverse-no-congrats]") {
  auto sr = TestingSessionRepo();
  auto id = SessionId{0};
  sr.add(id);
  auto pi =
      PalindromeEchoInteractor(SimplePalindromeDetector(), EchoInteractor(sr));

  auto in = EchoInput{.session_id = id, .message = "abc"};
  auto eout = SpyEchoPresenter();
  auto pout = SpyPalindromePresenter();
  pi.interact(in, eout, pout);
  REQUIRE(eout.responses.size() == 1);
  REQUIRE(eout.responses[0].message == "cba");
  REQUIRE(pout.responses.size() == 1);
  REQUIRE(pout.responses[0].is_palindrome == false);
}

TEST_CASE("echo reversed string and congrats", "[echo-reverse-and-congrats]") {
  auto pd = SimplePalindromeDetector();

  auto id = SessionId{0};
  auto sr = TestingSessionRepo();
  sr.add(id);
  auto pi = PalindromeEchoInteractor(pd, EchoInteractor(sr));

  auto eout = SpyEchoPresenter();
  auto pout = SpyPalindromePresenter();
  pi.interact(EchoInput{.session_id = id, .message = "aba"}, eout, pout);
  REQUIRE(eout.responses.size() == 1);
  REQUIRE(pout.responses.size() == 1);
  REQUIRE(pout.responses[0].is_palindrome == true);
}
