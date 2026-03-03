#ifndef SESSION_H_
#define SESSION_H_

#include <string>
#include <vector>

typedef std::string SessionId;

class SessionRepo {
public:
  virtual bool id_exists(const SessionId &) = 0;
  virtual void add(const SessionId &) = 0;
  virtual void remove(const SessionId &) = 0;
};

class TestingSessionRepo : public SessionRepo {
public:
  TestingSessionRepo();
  bool id_exists(const SessionId &);
  void add(const SessionId &);
  void remove(const SessionId &);

private:
  std::vector<SessionId> known_session_ids;
};

#endif // SESSION_H_
