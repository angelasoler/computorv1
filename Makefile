CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
TARGET = computor
SRC = computorv1.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)