CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
TARGET = computor
SRC = computorv1.cpp main.cpp
TEST_SRC = $(filter-out main.cpp, $(SRC))

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

test: $(TEST_SRC) test_computorv1.cpp
	$(CXX) $(CXXFLAGS) -o test_computorv1 test_computorv1.cpp $(TEST_SRCSRC) -lgtest -lgtest_main -pthread

run_tests: test
	./test_computorv1