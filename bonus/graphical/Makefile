##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## Makefile of the project
##

# Flags
NAME = 	pbrain-gomoku-ai-graphic

MAIN = 	src/main.cpp

SRC = 	src/GraphicLib/GraphicLib.cpp	\
		src/Map/Map.cpp \
		src/Parser/Parser.cpp \
		src/GameRules/GamesRules.cpp \

TEST_FILES	= \

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

CXXFLAGS 	= 	-std=c++20 -Wall -Wextra $(INCLUDE) -lraylib

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

fclean: clean
	@rm -f $(NAME)
	@$(call GREEN,"✅ [$@] done !")

re:	fclean all

run: $(NAME)
	./liskvork-bin
