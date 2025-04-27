CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
TARGET = computor
SRC = computorv1.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -rf
TEST_SRC = $(filter-out main.cpp, $(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean $(TARGET)

test: $(TEST_SRC) test_computorv1.cpp
	$(CXX) $(CXXFLAGS) -o test_computorv1 test_computorv1.cpp $(TEST_SRCSRC) -lgtest -lgtest_main -pthread

run_tests: test
	./test_computorv1

.PHONY: all clean fclean re 
