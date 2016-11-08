#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>

template <class InputIt> void print(InputIt begin, InputIt end) {
  std::cout << "[" << *begin;
  for (InputIt i = ++begin; i != end; i++) {
    std::cout << "," << *i;
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char const *argv[]) {
  // make a vector, calculate the reverse distance
  std::vector<int> v = {14, 100, 92, 3, 19, 20, 2};
  std::vector<int> u = {0, 0, 0, 0, 0, 0, 0};

  std::cout << "Pre: " << std::endl;
  print(v.begin(), v.end());
  print(u.begin(), u.end());

  std::cout << "copy from begin/end into begin" << std::endl;
  std::cout << "distance: " << std::distance(v.begin(), v.end()) << std::endl;
  std::copy(v.begin(), v.end(), u.rbegin());
  print(u.begin(), u.end());
  std::fill(u.begin(), u.end(), -10);

  std::cout << "copy from begin/end into rbegin" << std::endl;
  std::cout << "distance: " << std::distance(v.begin(), v.end()) << std::endl;
  std::copy(v.begin(), v.end(), u.rbegin());
  print(u.begin(), u.end());
  std::fill(u.begin(), u.end(), -10);

  std::cout << "copy from rbegin/rend into begin" << std::endl;
  std::cout << "distance: " << std::distance(v.rbegin(), v.rend()) << std::endl;
  std::copy(v.rbegin(), v.rend(), u.begin());
  print(u.begin(), u.end());
  std::fill(u.begin(), u.end(), -10);

  std::cout << "copy from rbegin/rend into rbegin" << std::endl;
  std::cout << "distance: " << std::distance(v.rbegin(), v.rend()) << std::endl;
  std::copy(v.rbegin(), v.rend(), u.rbegin());
  print(u.begin(), u.end());
  std::fill(u.begin(), u.end(), -10);

  //     auto back_dist = std::distance(v.rend(), v.rbegin());
  // std::cout << "backward: " << back_dist << std::endl;

  // auto back_bad_dist = std::distance(v.rbegin(), v.rend());
  // std::cout << "backward bad: " << back_bad_dist << std::endl;

  // size_t st_fwrd_dist = std::distance(v.begin(), v.end());
  // std::cout << "size_t forward: " << st_fwrd_dist << std::endl;

  // size_t st_back_dist = std::distance(v.rend(), v.rbegin());
  // std::cout << "size_t backward: " << st_back_dist << std::endl;

  return 0;
}