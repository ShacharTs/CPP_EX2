CXX = g++
CXXFLAGS = -g -Wall


.PHONY: test clean
OUTPUT = test

TEST_SRC = test.cpp SquareMat.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(OUTPUT): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $^



clean:
	rm -f *.o $(OUTPUT)