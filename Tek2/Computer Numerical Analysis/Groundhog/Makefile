##
## EPITECH PROJECT, 2021
## B-CNA-410-MPL-4-1-groundhog-alexandre.juan
## File description:
## Makefile
##

SRC_MAIN	=	src/main.cpp\
				src/groundhog.cpp

SRC_TEST 	=	\

NAME		=		groundhog

TEST_NAME	=	unit_tests

TEST_FLAG	=	-lcriterion --coverage

CFLAGS		=	-W -Wall -Wextra -C

all: $(NAME)

$(NAME):	$(OBJ_MAIN)
			g++ $(CFLAGS) $(SRC_MAIN) -o $(NAME)

clean :
			rm -rf $(OBJ_MAIN)
			rm -rf *.gc*
			rm -rf tests/*.gc*

fclean :	clean
			rm -rf $(NAME)
			rm -rf a.out

re :		fclean all

tests_run:
			g++ $(SRC_TEST) --coverage -lcriterion -o $(TEST_NAME)
			$(TEST_NAME)
			gcovr


