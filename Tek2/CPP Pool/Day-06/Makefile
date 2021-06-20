##
## EPITECH PROJECT, 2021
## Desktop
## File description:
## Makefile
##

all:	$(NAME)

$(NAME):
	make -C ex00
	make -C ex01

clean:
	make clean -C ex00
	make clean -C ex01

fclean:	clean
	make fclean -C ex00
	make fclean -C ex01

re:	fclean all

tests_run:
	make tests_run -C ex00
	make tests_run -C ex01
