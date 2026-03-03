#ifndef PALINDROME_H_
#define PALINDROME_H_

#include "echo.h"
#include <string>

struct PalindromeResponse {
  std::string message;
  bool is_palindrome;
};

class PalindromeDetector {
public:
  virtual bool detect(const std::string &s) const = 0;
};

class SimplePalindromeDetector : public PalindromeDetector {
public:
  bool detect(const std::string &s) const;
};

class PalindromeOutputPort {
public:
  virtual void present(const PalindromeResponse &r) = 0;
};

class SpyPalindromePresenter : public PalindromeOutputPort {
public:
  SpyPalindromePresenter();
  void present(const PalindromeResponse &r);
  std::vector<PalindromeResponse> responses;
};

class PalindromeEchoInteractor {
public:
  PalindromeEchoInteractor(const PalindromeDetector &pd,
                           const EchoInteractor &i);
  void interact(const EchoInput &, EchoOutputPort &, PalindromeOutputPort &);

private:
  const PalindromeDetector &palindrome_detector;
  const EchoInteractor &echo_interactor;
};

#endif // PALINDROME_H_
