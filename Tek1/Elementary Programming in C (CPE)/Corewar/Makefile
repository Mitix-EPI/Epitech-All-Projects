##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile
##

NAME = yolo

all	: $(NAME)

$(NAME)	:
	make -C asm
	make -C corewar

clean	:
	make clean -C asm
	make clean -C corewar

fclean	:	clean
	make fclean -C asm
	make fclean -C corewar

tests_run	:
	make tests_run -C asm

re	:	fclean all