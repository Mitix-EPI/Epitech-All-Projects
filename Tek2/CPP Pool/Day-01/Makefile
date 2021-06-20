##
## EPITECH PROJECT, 2021
## B-CPP-300-MPL-3-1-CPPD01-alexandre.juan
## File description:
## Makefile
##

NAME = yolo

all	: $(NAME)

$(NAME)	:
	make -C ex00
	make -C ex01

clean	:
	make clean -C ex00
	make clean -C ex01

fclean	:	clean
	make fclean -C ex00
	make fclean -C ex01

tests_run	:
	make tests_run -C ex00

re	:	fclean all