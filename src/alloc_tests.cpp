#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdlib>

int main(int argc, char const *argv[])
{
	std::cout<<"Allocation tests."<<std::endl;
	// define a type for the elements
	// Currently: single byte
	typedef unsigned long elem_t;
	for(int i = 1; i < 32; i++){
		size_t elem_c = (1 << i) - 1;
		std::cout << "Allocating: (2^"<< i <<")-1 = " 
			<< elem_c << " elements / ";
		std::cout << (sizeof(elem_t) * elem_c) << " bytes." << std::endl;
		// allocate ((2^i) - 1) * sizeof(elem_t) bytes
		std::vector<elem_t> v(elem_c);
		// initialise it 
		std::fill(v.begin(), v.end(), 42);		
		
		// sum it
		elem_t acc = 0;
		for(auto elem : v){
			acc += elem;
		}
		
		// check the result and print
		if(acc != (elem_c * 42)){
			std::cout << "Incorrect results. Expected: " << (elem_c * 42) 
				<< " Got: " << acc << std::endl;
		}else{
			std::cout << "Total: " << acc << std::endl;	
		}
	}
	return 0;
}