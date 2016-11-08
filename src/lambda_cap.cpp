#include <iostream>

template <typename Lambda> int call(Lambda f, int i) {
  auto f2 = [f](int j) { return f(j) + f(j); };
  return f2(i);
}

int main(int argc, char const *argv[]) {
  int m = 2;
  auto l = [&m](int i) {
    m++;
    return i * m;
  };
  std::cout << call(l, 10) << std::endl;
}
