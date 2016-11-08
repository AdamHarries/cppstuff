#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>

int main(int argc, char const *argv[]) {
  // make a vector, calculate the reverse distance
  std::vector<int> v = {14, 100, 92, 3, 19, 20, 2};

  auto fwrd_dist = std::distance(v.begin(), v.end());
  std::cout << "forward: " << fwrd_dist << std::endl;

  auto fwrd_bad_dist = std::distance(v.end(), v.begin());
  std::cout << "forward bad: " << fwrd_bad_dist << std::endl;

  auto back_dist = std::distance(v.rend(), v.rbegin());
  std::cout << "backward: " << back_dist << std::endl;

  auto back_bad_dist = std::distance(v.rbegin(), v.rend());
  std::cout << "backward bad: " << back_bad_dist << std::endl;

  size_t st_fwrd_dist = std::distance(v.begin(), v.end());
  std::cout << "size_t forward: " << st_fwrd_dist << std::endl;

  size_t st_back_dist = std::distance(v.rend(), v.rbegin());
  std::cout << "size_t backward: " << st_back_dist << std::endl;

  return 0;
}