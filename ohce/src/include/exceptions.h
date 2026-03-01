#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <exception>

class InteractOnStoppedSessionException : public std::exception {
  public:
    explicit InteractOnStoppedSessionException();
    const char *what() const noexcept override;
};
#endif // EXCEPTIONS_H_
