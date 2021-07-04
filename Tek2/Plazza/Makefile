##
## EPITECH PROJECT, 2021
## B-CNA-410-MPL-4-1-groundhog-alexandre.juan
## File description:
## Makefile
##

CC =	g++

SRC_MAIN	=	src/main.cpp\
				src/Plazza.cpp\
				src/Kitchen.cpp\
				src/Cooks.cpp\
				src/Messenger.cpp\
				src/Errors.cpp\
				src/Logfile.cpp\
				src/Thread.cpp\
				src/Thread_pool.cpp\
				src/ConditionVariable.cpp\
				src/DisplayLog.cpp\

SRC_TEST 	=	\

NAME		=		plazza

TEST_NAME	=	unit_tests

TEST_FLAG	=	-lcriterion --coverage

CPPFLAGS	= -W -Wall -Wextra -lrt -lpthread

all: $(NAME)

$(NAME):
			$(CC) $(SRC_MAIN) $(CPPFLAGS) -o $(NAME) -I./include -g3

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


