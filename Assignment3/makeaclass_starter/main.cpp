#include "class.cpp"
#include <type_traits>
#include <vector>

/*
 * Assigment 3: Make a class!
 * Requirements:
 * Must have a custom constructor ❌
 * Must have a default constructor ❌
    - i.e. constructor overloading
 * Must have private members (functions and/or variables) ❌
 * Must have public members (functions) ❌
 * Must have at least one getter function ❌
 * Must have at least one setter function ❌
 */

template <typename T, typename U> auto smarterMyMin(T a, U b) {
  return a < b ? a : b;
}

class functor {
public:
  int operator() (int arg) const {
    return num + arg;
  };

  functor(int num): num{num} {};
private:
  int num;
};

int main() {
  functor f(3);
  std::cout << f(5);
  return 0;
}