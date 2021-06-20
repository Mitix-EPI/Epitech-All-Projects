##
## EPITECH PROJECT, 2021
## cpp_poolday15
## File description:
## Makefile
##

NAME = cppPoolDay15

all: $(NAME)

$(NAME):
	make -C ex00
	make -C ex01

clean:
	make clean -C ex00
	make clean -C ex01

fclean:		clean
		make fclean -C ex00
		make fclean -C ex01

tests_run:
	make tests_run -C ex00
	make tests_run -C ex01

re:		fclean all