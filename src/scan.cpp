#include <iostream>
#include <vector>

auto add = [](int a, int b){ return a + b; };

template <class BinaryOperation, class T>
void iteration(std::vector<int>& in, std::vector<int>& out, int i,
  T init, BinaryOperation op){
  int vl = in.size();
  int td = 1 << (i-1);
  for(int j = 0;j<in.size();j++){
    if(j < vl && j >= td){
      out[j] = op(in[j - td], in[j]);
    }else{
      out[j] = in[j];
    }
  }
}

template <class InputIterator> 
void cntPrint(InputIterator b, InputIterator e){
  std::cout<<"["<<(*b);
  for(b++;b!=e;b++){
    std::cout<<","<<(*b);
  }std::cout<<"]\n";
}

int main(int argc, char const *argv[])
{
  // vectors
  std::vector<int> v = {0,1,2,3,4,5,6,7};
  std::vector<int> w(v.size());

  std::vector<int> iv(v);

  // initial value, and added to v
  int init = 0;
  v[0] += init;

  auto vt(v);
  for(int i = 1;i<vt.size();i++){
    v[i] = vt[i-1];
  }

  // print V before
  std::cout<<"V: ";
  cntPrint(v.begin(), v.end());

  // calculate number of iterations
  int iterations = 0;
  for(size_t vs = v.size() >> 1; vs > 0; vs >>= 1){
    iterations++;
  }
  if((v.size() & (v.size() - 1)) != 0) {
    iterations++;
  }  

  // iterate
  int i = 1;
  do {
    if(i % 2){
      iteration(v, w, i, init, add);
    }else{
      iteration(w, v, i, init, add);
    }
    i++;
  } while(i <= iterations);

  // for(int i = 0;i<v.size();i++){
  //   w[i] = init + w[i] - iv[i];
  // }

  // print
  std::cout<<"W: ";
  cntPrint(w.begin(), w.end());

  return 0;
}

