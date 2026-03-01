#ifndef DISPLAY_H_
#define DISPLAY_H_
#include <string>
#include <vector>

class Display {
  public:
    virtual ~Display() = default;
    virtual void insert(const std::string &message) = 0;
    virtual void render() = 0;
};

class FakeDisplay : public Display {
  public:
    void render() override;
    void insert(const std::string &message) override;
    const std::vector<std::string> &content() const { return lines_; }

  private:
    std::vector<std::string> lines_;
};

#endif // DISPLAY_H_
