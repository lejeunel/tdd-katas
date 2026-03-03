#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <exception>

class SessionNotFoundException : public std::exception {
public:
  explicit SessionNotFoundException();
  const char *what() const noexcept override;
};
#endif // EXCEPTIONS_H_
