#include <iostream>
#include <iterator>
#include <algorithm>
#include <map>

int main(int argc, char const *argv[])
{
  std::map<char, int> m;
  m['a'] = 1042;
  m['b'] = 1043;
  m['c'] = 1066;
  m['d'] = 1666;
  m['e'] = 1776;

  std::cout<<"M: " <<std::endl;
  std::cout<<"{"<<std::endl;
  for(auto p:m){
    std::cout<<"  ("<<p.first<<","<<p.second<<")"<<std::endl;
  } std::cout<<"}"<<std::endl;

  std::map<char, int> result;

  // Doesn't work: result.begin is not an output iterator
  // std::copy(m.begin(), m.end(), result.begin());

  // Might work?
  std::copy(m.begin(), m.end(), std::inserter(result, result.begin()));

  std::cout<<"Result: " <<std::endl;
  std::cout<<"{"<<std::endl;
  for(auto p:result){
    std::cout<<"  ("<<p.first<<","<<p.second<<")"<<std::endl;
  } std::cout<<"}"<<std::endl;
  
  return 0;
}