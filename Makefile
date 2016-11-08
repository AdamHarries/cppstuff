PREAMBLE = -std=c++11 -Iinc
FORMAT = clang-format-3.5 -i

all: bin/ic bin/at bin/dt bin/bi bin/ct bin/scan bin/ctc bin/lt bin/mi bin/ra bin/lc

clean:
	rm bin/ic bin/at bin/dt bin/bi bin/ct bin/scan

bin/ic: src/iteration_count.cpp
	$(FORMAT) src/iteration_count.cpp
	g++ $(PREAMBLE) src/iteration_count.cpp -o bin/ic

bin/at: src/alloc_tests.cpp
	$(FORMAT) src/alloc_tests.cpp
	g++ $(PREAMBLE) src/alloc_tests.cpp -o bin/at

bin/dt: src/distance_test.cpp
	$(FORMAT) src/distance_test.cpp
	g++ $(PREAMBLE) src/distance_test.cpp -o bin/dt

bin/bi: src/back_inserter.cpp
	$(FORMAT) src/back_inserter.cpp
	g++ $(PREAMBLE) src/back_inserter.cpp -o bin/bi

bin/ct: src/copy_tests.cpp
	$(FORMAT) src/copy_tests.cpp
	g++ $(PREAMBLE) src/copy_tests.cpp -o bin/ct

bin/scan: src/scan.cpp
	$(FORMAT) src/scan.cpp
	g++ $(PREAMBLE) src/scan.cpp -o bin/scan

bin/ctc: src/const_counter.cpp
	$(FORMAT) src/const_counter.cpp
	g++ $(PREAMBLE) src/const_counter.cpp -o bin/ctc	

bin/lt: src/lambda_types.cpp inc/function_traits.hpp inc/type_name.hpp
	$(FORMAT) src/lambda_types.cpp
	g++ $(PREAMBLE) src/lambda_types.cpp -o bin/lt

bin/mi: src/multimap_includes.cpp
	$(FORMAT) src/multimap_includes.cpp
	g++ $(PREAMBLE) src/multimap_includes.cpp -o bin/mi

bin/ra: src/riter_algorithms.cpp
	$(FORMAT) src/riter_algorithms.cpp
	g++ $(PREAMBLE) src/riter_algorithms.cpp -o bin/ra

bin/lc: src/lambda_cap.cpp
	$(FORMAT) src/lambda_cap.cpp
	g++ $(PREAMBLE) src/lambda_cap.cpp -o bin/lc