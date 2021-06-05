##
## EPITECH PROJECT, 2021
## B-OOP-400-MPL-4-1-arcade-richard.habimana
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

CC =	g++

NAME_NIBBLER =		arcade_nibbler.so

SRC_NIBBLER = main_nibbler.cpp\
			Nibbler.cpp\
			SnakeBody.cpp\
			Fruit.cpp\
			../../UtilityClasses/Vector2i.cpp\
			../../UtilityClasses/Vector2f.cpp\
			../../UtilityClasses/Vector3i.cpp\
			../../UtilityClasses/Settings.cpp\
			../../UtilityClasses/Object.cpp\
			../../UtilityClasses/Leaderboard.cpp\

build_nibbler:
	@echo "${GREEN}\n-----------\nBuilding nibbler"
	$(CC) -c $(SRC_NIBBLER) -I./../../../include -fPIC
	$(CC) -shared *.o -o $(NAME_NIBBLER)
	cp $(NAME_NIBBLER) ../../../lib/.
	rm -rf $(NAME_NIBBLER)
	@echo "Finished building nibbler\n-----------\n${RESET}"

clean:
	@echo "${GREEN}\n-----------\nCleaning nibbler"
	rm -f *.o
	rm -rf *.gc*
	rm -rf tests/*.gc*
	@echo "Finished cleaning nibbler\n-----------\n${RESET}"

fclean: clean
	@rm -rf $(NAME_NIBBLER)

re : fclean all

all: build_nibbler