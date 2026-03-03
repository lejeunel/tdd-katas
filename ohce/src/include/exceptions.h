#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <exception>

class StoppedSessionException : public std::exception {
public:
  explicit StoppedSessionException();
  const char *what() const noexcept override;
};

class SessionNotFoundException : public std::exception {
public:
  explicit SessionNotFoundException();
  const char *what() const noexcept override;
};
#endif // EXCEPTIONS_H_
