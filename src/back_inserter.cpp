// back_insert_iterator example
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
#include <type_name.hpp>

int main() {
  // the things from the C++ website
  std::vector<int> foo, bar;
  for (int i = 1; i <= 5; i++) {
    foo.push_back(i);
    bar.push_back(i * 10);
  }

  std::back_insert_iterator<std::vector<int>> back_it(foo);

  std::copy(bar.begin(), bar.end(), back_it);

  std::cout << "foo:";
  for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  // my things
  std::vector<int> fizz;

  for (int i = 0; i < 5; i++) {
    fizz.push_back((i + 1) * 2);
  }

  std::cout << "Fizz before: ";
  for (auto f : fizz) {
    std::cout << f << ",";
  }
  std::cout << std::endl;

  std::back_insert_iterator<std::vector<int>> fizz_back_it(fizz);

  std::copy(fizz.begin(), fizz.end(), fizz_back_it);

  std::cout << "Fizz after: ";
  for (auto f : fizz) {
    std::cout << f << ",";
  }
  std::cout << std::endl;

  std::list<int> l = {1, 2, 3, 4, 5};

  std::cout << "L before: ";
  for (auto f : l) {
    std::cout << f << ",";
  }
  std::cout << std::endl;

  std::cout << "Before insertion/copy." << std::endl;

  auto l_bi = std::back_inserter(l);

  std::copy_n(l.begin(), 5, l_bi);

  std::cout << "L after: ";
  for (auto f : l) {
    std::cout << f << ",";
  }
  std::cout << std::endl;

  std::cout << "After insertion/copy." << std::endl;

  // seeing if we can get the type from a back inserter
  typedef std::iterator_traits<decltype(l_bi)>::pointer it_p_type;
  std::cout << "Iterator pointer type: " << type_name<it_p_type>() << std::endl;

  return 0;
}
