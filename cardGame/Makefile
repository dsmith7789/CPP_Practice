# Makefile

CXX = g++
CXXFLAGS = -std=c++17

SRC = Test.cpp Card.cpp Hand.cpp Deck.cpp Tests/Basics/testBasicHand.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = Test

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
