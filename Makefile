CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

test:
	$(CXX) $(CXXFLAGS) src/MyBigNumber.cpp tests/test_MyBigNumber.cpp -o test_runner
	./test_runner

clean:
	rm -f test_runner test_runner.exe
