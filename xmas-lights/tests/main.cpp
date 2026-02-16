#include <catch2/catch_session.hpp>
#include <catch2/interfaces/catch_interfaces_config.hpp>

int main(int argc, char *argv[]) {
  Catch::Session session;

  using namespace Catch::Clara;
  auto cli = session.cli();

  session.cli(cli);

  return session.run();
}
