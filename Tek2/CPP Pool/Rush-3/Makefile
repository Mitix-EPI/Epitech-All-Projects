##
## EPITECH PROJECT, 2021
## B-CPP-300-MPL-3-1-CPPrush3-clement.bolin
## File description:
## Makefile
##

SRC_MAIN	=	main.cpp\
				Display/Ncurse.cpp\
				Modules/Cpu.cpp\
				Modules/Memory.cpp\
				Modules/User.cpp\
				Modules/Time.cpp\
				Modules/Network.cpp\
				Modules/Tasks.cpp\
				MonitorCore/MonitorModule.cpp\
				MonitorCore/MonitorDisplay.cpp\

SRC_TEST 	=	\

NAME		=		MyGKrellm

TEST_NAME	=	unit_tests

TEST_FLAG	=	-lcriterion --coverage

CFLAGS		=	-W -Wall -Wextra -C

SFMLFLAG	=	-lsfml-window -lsfml-graphics -lsfml-audio -lsfml-system

all: $(NAME)

$(NAME):	$(OBJ_MAIN)
			g++ $(CFLAGS) $(SRC_MAIN) -lncurses -o $(NAME)

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


