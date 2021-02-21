##
## EPITECH PROJECT, 2020
## CPE_dante_2019
## File description:
## Makefile
##

NAME = fake

all	: $(NAME)

$(NAME)	:
	make -C generator
	make -C solver

clean	:
	make clean -C generator
	make clean -C solver

fclean	:	clean
	make fclean -C generator
	make fclean -C solver

re	:	fclean all

tests_run	:
	make tests_run -C generator
	make tests_run -C solver