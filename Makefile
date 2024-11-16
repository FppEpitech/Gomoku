##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## Makefile of the project
##

# Flags
NAME = pbrain-gomoku-ai

MAIN = src/main.cpp

SRC = 	src/Parser/Parser.cpp \
		src/Map/Map.cpp \
		src/Map/canAlign.cpp \
		src/Map/winPatterns.cpp \
		src/GameRules/GamesRules.cpp \
		src/Algorithms/Algorithm.cpp \
		src/Algorithms/miniMax.cpp \
		src/Algorithms/evaluation.cpp \



TEST_FILES	= 	easy_win/test_easy_win.cpp \
				avoid_lose/test_avoid_loose.cpp \
				complexPattern/test_complexPattern.cpp \

# Tests
TEST_NAME 	= 	unit_tests
TEST_DIR 	= 	./tests/
TEST 		= 	$(addprefix $(TEST_DIR), $(TEST_FILES))
TEST_OBJ 	= 	$(TEST:.cpp=.o)
TEST_GCNO 	= 	$(SRC:.cpp=.gcno)
TEST_GCDA 	= 	$(SRC:.cpp=.gcda)
TEST_FLAGS 	= 	-Wall -Wextra -Werror --coverage -lcriterion


# Flags
OBJ			=	$(SRC:.cpp=.o)
MAIN_OBJ	=	$(MAIN:.cpp=.o)
INCLUDE = -I./src

CXXFLAGS 	= 	-std=c++20 -Wall -Wextra $(INCLUDE)

# Colors
YELLOW 		= 	/bin/echo -e "\x1b[33m $1\x1b[0m"
GREEN 		= 	/bin/echo -e "\x1b[32m $1\x1b[0m"

CC	=	g++

%.o: %.cpp
	@$(CC) -c $< -o $@ $(CXXFLAGS) && \
	$(call YELLOW,"🆗 $<") || \
	$(call YELLOW,"❌ $<")

all: $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ)
	@$(CC) $(MAIN_OBJ) $(OBJ) -o $(NAME) $(CXXFLAGS) && \
	$(call YELLOW,"✅ $@") || \
	$(call YELLOW,"❌ $@")


clean:
	rm -f $(MAIN_OBJ) $(OBJ)
	@$(call GREEN,"✅ [$@] done !")
	- rm output.log
	- rm board.log

obj: $(OBJ)

test_obj: $(TEST_OBJ)

fclean: clean tests_clean
	@rm -f $(NAME)
	@$(call GREEN,"✅ [$@] done !")

tests_clean:
	- rm ${TEST_NAME}
	- rm -f $(OBJ) $(TEST_OBJ) $(TEST_GCNO) $(TEST_GCDA)
	@$(call GREEN,"✅ [$@] done !")

tests_run: fclean
	$(MAKE) obj CXXFLAGS+="--coverage $(INCLUDE)"
	$(MAKE) test_obj CXXFLAGS="-Wall -Wextra -Werror $(INCLUDE)"
	@$(CC) -o $(TEST_NAME) $(OBJ) $(TEST_OBJ) $(TEST_FLAGS) $(INCLUDE)
	./$(TEST_NAME)
	gcovr --exclude tests/

re:	fclean all

IMAGE	= epitechcontent/epitest-docker

docker:
	sudo docker run -it -v $(shell pwd):/app --workdir /app $(IMAGE)

run: $(NAME)
	cp tests/liskvork-bin ./
	cp tests/config.ini ./
	./liskvork-bin
	rm -f liskvork-bin
	rm -f config.ini

run-test-against-v1: $(NAME)
	cp tests/liskvork-bin ./
	cp tests/config-aiv1-run.ini ./config.ini
	./liskvork-bin
	rm -f liskvork-bin
	rm -f config.ini
