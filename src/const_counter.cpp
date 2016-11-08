#include <iostream>

template<int N>
struct flag {
  friend constexpr int adl_flag (flag<N>);
};
template<int N>
struct writer {
  friend constexpr int adl_flag (flag<N>) {
    return N;
  }

  static constexpr int value = N;
};
template<int N, class = char[noexcept(adl_flag(flag<N> ()))?+1:-1]>
int constexpr reader (int, flag<N>) {
  return N;
}
template<int N>
int constexpr reader (float, flag<N>, int R = reader (0, flag<N-1> ())) {
  return R;
}
int constexpr reader (float, flag<0>) {
  return 0;
}
template<int N = 1, int C = reader (0, flag<32> ())>
int constexpr next (int R = writer<C + N>::value) {
  return R;
}
int main () {
  constexpr int a = next ();
  constexpr int b = next ();
  constexpr int c = next ();

  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;
  std::cout << "c: " << c << std::endl;

  static_assert (a == 1 && b == a+1 && c == b+1, "try again");
}
