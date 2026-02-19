#ifndef WARDROBE_H_
#define WARDROBE_H_

class Wardrobe {
  public:
    Wardrobe(const int &size);
    int get_size() const;

  private:
    int size;
};

#endif // WARDROBE_H_
