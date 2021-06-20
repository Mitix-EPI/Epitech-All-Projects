##
## EPITECH PROJECT, 2021
## my_ftp
## File description:
## Makefile
##

##################################
SRC_MAIN_CLIENT =	$(shell find client -name "*.c")

SRC_CLIENT	=		$(filter-out client/main.c, $(SRC_MAIN_CLIENT))

SRC_TEST_CLIENT = 	$(wildcard client/tests/*.c)\

OBJ_MAIN_CLIENT =	$(SRC_MAIN_CLIENT:.c=.o)

NAME_CLIENT =		myclient
##################################

##################################
SRC_MAIN_SERVER =	$(shell find server -name "*.c")

SRC_SERVER	=		$(filter-out server/main.c, $(SRC_MAIN_SERVER))

SRC_TEST_SERVER = 	$(wildcard server/tests/*.c)\

OBJ_MAIN_SERVER =	$(SRC_MAIN_SERVER:.c=.o)

NAME_SERVER =		myftp
##################################


TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

CFLAGS = -W -Wall -Wextra -C -g3 -I../include

all: server client

client:	$(OBJ_MAIN_CLIENT)
	gcc $(CFLAGS) $(OBJ_MAIN_CLIENT) -o $(NAME_CLIENT)
	make clean
	cp $(NAME_CLIENT) ../.

server:	$(OBJ_MAIN_SERVER)
	gcc $(CFLAGS) $(OBJ_MAIN_SERVER) -o $(NAME_SERVER)
	make clean
	cp $(NAME_SERVER) ../.

clean :
			rm -f $(OBJ_MAIN_CLIENT)
			rm -f $(OBJ_MAIN_SERVER)
			rm -rf *.gc*
			rm -rf tests/*.gc*

fclean :	clean
			rm -rf $(NAME_CLIENT)
			rm -rf $(NAME_SERVER)
			rm -rf $(TEST_NAME)
			rm -f tests/*.o

re :		fclean	\
			all

tests_run:	$(TEST_NAME)

$(TEST_NAME):	@echo "unit_tests"

#gcovr -r . --html --html-details -o ~/rapport.html