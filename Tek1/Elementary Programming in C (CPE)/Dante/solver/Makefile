##
## EPITECH PROJECT, 2019
## my_ls
## File description:
## Makefile
##

CFLAGS = -W -Wall -Wextra -I./include

C_LIB = -I./include -L./lib/my -lmy

TEST = tests/test_issafe.c \
		tests/test_check_all_width.c\
		tests/test_end_solve.c

SRC_TEST = src/solver.c\
			src/end_solve.c

SRC = src/main.c\
	src/solver.c\
	src/end_solve.c

OBJ = $(SRC:.c=.o)

NAME = solver

all	: $(NAME)

$(NAME)	:	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(C_LIB)

clean	:
	rm -f $(OBJ)
	make clean -C lib/my

fclean	:	clean
	make fclean -C lib/my
	rm -f $(NAME)
	rm -f *.gcno
	rm -f *.gcda
	rm -f units

re	:	fclean all

tests_run	:
	make -C lib/my
	gcc -o units $(SRC_TEST) $(TEST) $(C_LIB) -lcriterion --coverage
	./units
	gcovr --exclude tests