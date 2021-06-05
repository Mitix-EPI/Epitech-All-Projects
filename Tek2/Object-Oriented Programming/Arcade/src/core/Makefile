##
## EPITECH PROJECT, 2021
## cpp
## File description:
## Makefile
##

ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif

SRC =	./main.cpp\
		../UtilityClasses/Vector2i.cpp\
		../UtilityClasses/Vector3i.cpp\
		../UtilityClasses/Settings.cpp\
		./CoreModule.cpp\
		./Encapsulation.cpp\

CC =	g++

NAME =		arcade

CFLAGS = -Wall -Wextra -Werror -ldl -g3

all:	$(NAME)

$(NAME):
	@echo "${BLUE}\n-----------\nBuilding Core"
	$(CC) $(SRC) $(CFLAGS) -o $(NAME) -I./../../include
	cp $(NAME) ../../.
	rm -f $(NAME)
	@echo "Finished building Core\n-----------\n${RESET}"

clean:
	@echo "${BLUE}\n-----------\nCleaning Core"
	rm -f *.o
	rm -rf *.gc*
	rm -rf tests/*.gc*
	@echo "Finished cleaning Core\n-----------\n${RESET}"

fclean:	clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re