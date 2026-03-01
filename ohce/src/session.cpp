#include "include/session.h"

Session::Session(const std::string &a_username)
    : username(a_username), is_stopped_(false) {};

const std::string &Session::get_username() const { return username; }

bool Session::is_stopped() const { return is_stopped_; }

void Session::stop() { is_stopped_ = true; }
