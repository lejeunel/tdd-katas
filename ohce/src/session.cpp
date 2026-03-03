#include "include/session.h"
#include <cstddef>

TestingSessionRepo::TestingSessionRepo() {};
bool TestingSessionRepo::id_exists(const SessionId &id) {
  for (std::size_t i = 0; i < known_session_ids.size(); ++i)
    if (known_session_ids[i] == id)
      return true;

  return false;
};
void TestingSessionRepo::add(const SessionId &id) {
  known_session_ids.push_back(id);
};
void TestingSessionRepo::remove(const SessionId &id) {
  std::erase(known_session_ids, id);
};
