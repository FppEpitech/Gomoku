##
## EPITECH PROJECT, 2024
## MyGomoku
## File description:
## Makefile
##

NAME = pbrain-gomoku-ai

MAIN = src/main.py

all: $(NAME)

$(NAME):
	cp $(MAIN) $(NAME)
	chmod +x $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re:	fclean all
