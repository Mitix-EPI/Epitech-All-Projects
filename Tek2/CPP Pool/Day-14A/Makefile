##
## EPITECH PROJECT, 2021
## B-CPP-300-MPL-3-1-CPPD14A-alexandre.juan
## File description:
## Makefile
##

NAME = cppPoolDay14A

all: $(NAME)

$(NAME):
	make -C ex00
	make -C ex02

clean:
	make clean -C ex00
	make clean -C ex02

fclean:		clean
		make fclean -C ex00
		make fclean -C ex02

tests_run:
	make tests_run -C ex00
	make tests_run -C ex02

re:		fclean all