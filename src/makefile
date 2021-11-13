RELEASE_FLAGS = -DNDEBUG -g -ffast-math -ftree-vectorize -O3 -march=native
DEBUG_FLAGS = -DDEBUG -g -fsanitize=address -fsanitize=undefined -fno-builtin -fno-omit-frame-pointer
FLAGS = -Wall -Wextra -lm -std=c++17 $(DEBUG_FLAGS)
all:
	g++ $(FLAGS) test_main.cpp questions.cpp -Wno-unused-parameter

clean:
	-rm -f a.out
