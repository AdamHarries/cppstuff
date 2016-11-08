#include <iostream>
#include <cstdlib>

int main(int argc, char const *argv[])
{
	std::cout << "Argument count: " << argc << std::endl;
	size_t vectorSize = 100;
	if(argc > 1){
		vectorSize = atoi(argv[1]);
	}
	std::cout << "Vector size: " << (int)vectorSize << std::endl;
	size_t iterations = 0;
	for(size_t vs = vectorSize >> 1; vs > 0; vs >>= 1){
		iterations++;
		std::cout << "  halfsize: " << (int)vs << std::endl;
	}
	if((vectorSize & (vectorSize - 1)) != 0){
		iterations++;
	}
	std::cout << "Iterations: " << (int)iterations << std::endl;
	return 0;
}
