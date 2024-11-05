##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## Makefile of the project
##

NAME = pbrain-gomoku-ai

MAIN = src/main.py

all: $(NAME)

$(NAME):
	cp $(MAIN) $(NAME)
	chmod +x $(NAME)

clean:
	rm -rf $(NAME)
	- rm output.log
	- rm board.log

fclean: clean

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
