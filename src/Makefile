OS := $(shell uname)

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror
LDFLAGS = -lncurses
GCOV_FLAGS = -fprofile-arcs -ftest-coverage --coverage
LINKFLAGS = -lstdc++ -lm

BUILD_DIR = build
SRC_DIR = .
TEST_DIR = ./test
GCOV_DIR = test/gcov
GCOV_EXEC = test/gcov/gcov_test

ifeq ($(OS), Darwin)
	GTEST_FLAGS = -I/opt/homebrew/opt/googletest/include -L/opt/homebrew/opt/googletest/lib -lgtest -lgtest_main -pthread
	OPEN_CMD = open
	LCOV_FLAG = --ignore-errors inconsistent
else
	GTEST_FLAGS = -I/usr/include/gtest -L/usr/lib -lgtest -lgtest_main -pthread
	OPEN_CMD = xdg-open
	LCOV_FLAG = 
endif

SOURCES_EXEC = brick_game/snake/snake_game.cpp gui/cli/cli_view.cpp game_params.cpp main.cpp brick_game/tetris/tetris_game.cpp
OBJECTS_EXEC = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES_EXEC))
EXECUTABLE = BrickGame

SOURCES_TEST = brick_game/snake/snake_game.cpp brick_game/tetris/tetris_game.cpp test/test.cpp
EXECUTABLE_TEST = test/test_bin

install:
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SOURCES_EXEC) $(LDFLAGS) -o $(EXECUTABLE)

test:
	$(CXX) $(CXXFLAGS) $(SOURCES_TEST) $(GTEST_FLAGS) -o $(EXECUTABLE_TEST)
	$(EXECUTABLE_TEST)

gcov_report:
	mkdir -p $(GCOV_DIR)
	$(CXX) $(CXXFLAGS) $(SOURCES_TEST) -o $(GCOV_EXEC) $(GTEST_FLAGS) $(GCOV_FLAGS) $(LINKFLAGS)
	./$(GCOV_EXEC)
ifeq ($(OS), Darwin)
	mv *.gcno *.gcda $(GCOV_DIR)
endif
	lcov --capture --directory $(GCOV_DIR) --output-file $(GCOV_DIR)/coverage.info $(LCOV_FLAG)
	lcov --remove $(GCOV_DIR)/coverage.info '/opt/homebrew/opt/googletest/*' '/usr/*' --output-file $(GCOV_DIR)/coverage.info $(LCOV_FLAG)
	genhtml -o $(GCOV_DIR)/report $(GCOV_DIR)/coverage.info $(LCOV_FLAG)
	$(OPEN_CMD) $(GCOV_DIR)/report/index.html

leaks_1:
	leaks -atExit -- ./build/BrickGame.app/Contents/MacOS/BrickGame tetris cli

leaks_2:
	leaks -atExit -- ./build/BrickGame.app/Contents/MacOS/BrickGame snake cli

leaks_3:
	leaks -atExit -- ./build/BrickGame.app/Contents/MacOS/BrickGame tetris desktop

leaks_4:
	leaks -atExit -- ./build/BrickGame.app/Contents/MacOS/BrickGame snake desktop

leaks_test: test
	leaks -atExit -- $(EXECUTABLE_TEST)

clang_format:
	find . -path ./build -prune -o \( -name "*.cpp" -o -name "*.h" \) -print | xargs clang-format -i -style="{BasedOnStyle: Google, IndentWidth: 4}"

clang_check:
	find . -path ./build -prune -o \( -name "*.cpp" -o -name "*.h" \) -print | xargs clang-format -n -style="{BasedOnStyle: Google, IndentWidth: 4}"

clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE) max_score_tetris.txt max_score_snake.txt $(EXECUTABLE_TEST) $(GCOV_DIR)

tetris: clean install
	./BrickGame tetris cli

snake: clean install
	./BrickGame snake cli

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./BrickGame tetris cli

.PHONY: all clean test