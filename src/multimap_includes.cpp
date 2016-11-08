#include <algorithm>
#include <iterator>
#include <map>

int main(int argc, char const *argv[])
{
  std::multimap<int, float> mm = 
    {{1,0.3f}, {4,0.1f}, {7,19.5f}, {23, 0.01f}, {2, 1.0f}};

  // auto mm_begin_it = std::begin(mm);
  auto mm_begin_it = mm.lower_bound(0);
  auto mm_end_it   = mm.upper_bound(110);

  typedef std::iterator_traits<decltype(mm_begin_it)>::value_type mm_it_type;

  std::vector<float> v = 
    {0.1f, 0.2f, 0.3f, 19.5f, 0.01f, 1.0f, 12.0f, 29.3f};


  // This won't work!
  // auto result = std::includes(
  //   std::begin(v), std::end(v),
  //   mm_begin_it, mm_end_it, 
  //   [=](mm_it_type t1, float t2){
  //     return t1.second < t2;
  //   });

  // Neither will this!
  // auto result2 = std::includes(
  //   std::begin(v), std::end(v),
  //   mm_begin_it, mm_end_it, 
  //   [](float t1, mm_it_type t2){
  //     return t1 == t2.second;
  //   });

  return 0;
}