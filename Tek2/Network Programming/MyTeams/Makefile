##
## EPITECH PROJECT, 2021
## B-NWP-400-MPL-4-1-myteams-alexandre.juan
## File description:
## Makefile
##

CC = gcc

##################################
SRC_MAIN_COMMON =	src/common/parse_command.c\
					src/common/parse_command2.c\
					src/common/get_next_line.c\

OBJ_MAIN_COMMON =	$(SRC_MAIN_COMMON:.c=.o)
##################################

##################################
SRC_MAIN_CLIENT =	$(shell find src/client -name "*.c")

SRC_CLIENT	=		$(filter-out src/client/main.c, $(SRC_MAIN_CLIENT))

SRC_TEST_CLIENT = 	$(wildcard src/client/tests/*.c)\

OBJ_MAIN_CLIENT =	$(SRC_MAIN_CLIENT:.c=.o)

NAME_CLIENT =		myteams_cli
##################################

##################################
SRC_MAIN_SERVER =	$(shell find src/server -name "*.c")

SRC_SERVER	=		$(filter-out src/server/main.c, $(SRC_MAIN_SERVER))

SRC_TEST_SERVER = 	$(wildcard src/server/tests/*.c)\

OBJ_MAIN_SERVER =	$(SRC_MAIN_SERVER:.c=.o)

NAME_SERVER =		myteams_server
##################################

TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

CFLAGS = -W -Wall -Wextra -Wattributes -C -g3 -I ./include -I ./libs/myteams

NAME = myteams_server

all: $(NAME)

$(NAME): server client

client:	$(OBJ_MAIN_COMMON) $(OBJ_MAIN_CLIENT)
	$(CC) $(OBJ_MAIN_COMMON) $(OBJ_MAIN_CLIENT) -L./libs/myteams -lmyteams -fPIC -luuid -o $(NAME_CLIENT)

server:	$(OBJ_MAIN_COMMON) $(OBJ_MAIN_SERVER)
	$(CC) $(OBJ_MAIN_COMMON) $(OBJ_MAIN_SERVER) -L./libs/myteams -lmyteams -fPIC -luuid -o $(NAME_SERVER)

clean :
	$(RM) -f $(OBJ_MAIN_CLIENT)
	$(RM) -f $(OBJ_MAIN_SERVER)
	$(RM) -f $(OBJ_MAIN_COMMON)
	$(RM) -rf *.gc*
	$(RM) -rf tests/*.gc*

fclean :	clean
			$(RM) -rf $(NAME_CLIENT)
			$(RM) -rf $(NAME_SERVER)
			$(RM) -rf $(TEST_NAME)
			$(RM) -f tests/*.o

re :		fclean	\
			all

tests_run:	$(TEST_NAME)

$(TEST_NAME):	$(SRC_TEST) $(SRC)
				$(CC) $(CFLAGS) $(TEST_FLAG) $(SRC) $(SRC_TEST) -o $(TEST_NAME)
				./unit_tests
				gcovr --exclude tests
				gcovr --exclude tests -b

#gcovr -r . --html --html-details -o ~/rapport.html