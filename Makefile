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
		src/GameRules/GamesRules.cpp

TEST = unit_tests

# Flags
OBJ			=	$(SRC:.cpp=.o)
MAIN_OBJ	=	$(MAIN:.cpp=.o)

CXXFLAGS 	= 	-std=c++20 -Wall -Wextra

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

IMAGE	= epitechcontent/epitest-docker

docker:
	sudo docker run -it -v $(shell pwd):/app --workdir /app $(IMAGE)

run: $(NAME)
	cp tests/liskvork-bin ./
	cp tests/config.ini ./
	./liskvork-bin
	rm -f liskvork-bin
	rm -f config.ini
