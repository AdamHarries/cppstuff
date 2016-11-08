#include <iostream>
#include <vector>
#include <typeinfo>
#include <iterator>
#include <function_traits.hpp>
#include <type_name.hpp>

template <typename T> class buffer {
  T *mem;

public:
  using reference = T &;
  using const_reference = const T &;

  buffer(int size) {
    std::cout << "Allocating buffer with element type: " << type_name<T>()
              << std::endl;
    mem = new T[size];
  }
  ~buffer() { delete[] mem; }
};

template <class BufferType = void, class Iterator>
buffer<BufferType> make_buffer_impl(Iterator b, size_t length,
                                    std::input_iterator_tag) {
  typedef typename std::iterator_traits<Iterator>::value_type IteratorType;
  std::cout << "input iterator" << std::endl;
  buffer<IteratorType> nbuf(length);
  return nbuf;
}

template <class BufferType = void, class Iterator>
buffer<BufferType> make_buffer_impl(Iterator b, size_t length,
                                    std::output_iterator_tag) {
  std::cout << "output iterator" << std::endl;
  buffer<BufferType> nbuf(length);
  return nbuf;
}

template <class BufferType = void, class Iterator>
buffer<BufferType> make_buffer(Iterator b, size_t length) {
  return make_buffer_impl<BufferType>(
      b, length, typename std::iterator_traits<Iterator>::iterator_category());
}

int main(int argc, char const *argv[]) {
  auto lambda = [](int i) { return long(i * 10); };

  typedef function_traits<decltype(lambda)> traits;

  traits::result_type tvar;

  std::cout << "Function return type: " << type_name<traits::result_type>()
            << std::endl;

  static_assert(std::is_same<long, traits::result_type>::value, "err");
  static_assert(std::is_same<int, traits::arg<0>::type>::value, "err");

  // make a buffer using the lambda type, and an initial vector
  std::vector<long> v = {0, 1, 2, 3, 4, 5, 6, 7};

  std::cout << "Allocating buffer from normal vector iterator" << std::endl;
  auto b = make_buffer<traits::result_type>(v.begin(),
                                            std::distance(v.begin(), v.end()));

  // now trying with a back insertion iterator
  std::cout << "Allocating buffer from back insert iterator" << std::endl;
  auto b2 = make_buffer<traits::result_type>(std::back_inserter(v),
                                             std::distance(v.begin(), v.end()));

  return 0;
}