#ifndef CLOCK_H_
#define CLOCK_H_
#include <ctime>

class Clock {
  public:
    virtual ~Clock() = default;
    virtual std::time_t now() const = 0;
};

class FakeClock : public Clock {
  public:
    FakeClock(const int hour);
    std::time_t now() const override;

  private:
    int hour;
};
#endif // CLOCK_H_
