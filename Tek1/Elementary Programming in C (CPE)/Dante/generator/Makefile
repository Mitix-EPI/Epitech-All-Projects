##
## EPITECH PROJECT, 2019
## my_ls
## File description:
## Makefile
##

CFLAGS = -W -Wall -Wextra -O1 -O2 -O3 -Ofast -I./include

C_LIB = -I./include -L./lib/my -lmy

TEST = tests/test_if_condition.c\
		tests/test_fill_perfect.c\
		tests/test_print_map.c\
		tests/test_create_map.c\
		tests/test_create_map2.c\
		tests/test_check_up_left_ite.c\
		tests/test_destroy_walls_ite.c

SRC_TEST = 	src/main_generator.c\
	src/print.c			\
	src/imperfect_map.c	\
	src/create_map.c	\
	src/create_algo.c	\
	src/main_generator2.c

SRC = src/main.c			\
	src/main_generator.c	\
	src/print.c				\
	src/imperfect_map.c		\
	src/create_map.c		\
	src/create_algo.c		\
	src/main_generator2.c	\

OBJ = $(SRC:.c=.o)

NAME = generator

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