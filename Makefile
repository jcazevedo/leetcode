CC_FILES = $(wildcard src/*.cpp)
BIN_FILES = $(patsubst src/%.cpp, %, $(CC_FILES))
CC_FLAGS = -Wall -Wextra -O2 -std=c++17
CC = g++

all: $(BIN_FILES)

%: src/%.cpp
	clang-format -i $<
	$(CC) $(CC_FLAGS) -DLOCAL -o $@ -c $<

format:
	clang-format -i src/*.cpp

clean:
	rm -f $(BIN_FILES)
