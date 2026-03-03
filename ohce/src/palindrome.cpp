#include "include/palindrome.h"
#include "include/echo.h"
#include <cstddef>

bool SimplePalindromeDetector::detect(const std::string &s) const {
  if (s.size() == 0)
    return false;

  if (s.size() / 2 == 0)
    return false;

  for (size_t i = 0; i < s.size() / 2; ++i)
    if (s[i] != s[s.size() - i - 1])
      return false;

  return true;
}

SpyPalindromePresenter::SpyPalindromePresenter() {};
void SpyPalindromePresenter::present(const PalindromeResponse &r) {
  responses.push_back(r);
};

PalindromeEchoInteractor::PalindromeEchoInteractor(const PalindromeDetector &pd,
                                                   const EchoInteractor &i)
    : palindrome_detector(pd), echo_interactor(i) {};

void PalindromeEchoInteractor::interact(const EchoInput &in,
                                        EchoOutputPort &eout,
                                        PalindromeOutputPort &pout) {
  echo_interactor.interact(in, eout);

  auto r = PalindromeResponse{.message = in.message, .is_palindrome = false};
  if (palindrome_detector.detect(in.message))
    r.is_palindrome = true;

  pout.present(r);
};
