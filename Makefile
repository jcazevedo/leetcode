CC_FILES = $(wildcard src/*.cpp)
BIN_FILES = $(patsubst src/%.cpp, %, $(CC_FILES))
CC_FLAGS = -Wall -O2 -std=c++11
CC = g++

all: $(BIN_FILES)

%: src/%.cpp
	$(CC) $(CC_FLAGS) -o $@ -c $<

format:
	clang-format -i src/*.cpp

clean:
	rm -f $(BIN_FILES)
