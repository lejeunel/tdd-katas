#ifndef SESSION_H_
#define SESSION_H_
#include <string>

class Session {
public:
  Session(const std::string &username);
  const std::string &get_username() const;
  bool is_stopped() const;
  void stop();

private:
  std::string username;
  bool is_stopped_ = false;
};

#endif // SESSION_H_
