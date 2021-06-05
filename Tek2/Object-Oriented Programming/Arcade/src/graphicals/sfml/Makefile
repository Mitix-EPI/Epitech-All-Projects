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

NAME_SFML =		arcade_sfml.so

SRC_SFML	=	sfml.cpp\
				../../Errors/error.cpp\
				../../UtilityClasses/Vector2i.cpp\
				../../UtilityClasses/Vector3i.cpp\
				../../UtilityClasses/Settings.cpp\
				../../UtilityClasses/Leaderboard.cpp\

build_sfml:
	@echo "${LIGHTPURPLE}\n-----------\nBuilding SFML"
	$(CC) -c $(SRC_SFML) -Wall -Wextra -Werror -I../../../include -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -fPIC 
	$(CC) -shared *.o -o $(NAME_SFML) -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
	cp $(NAME_SFML) ../../../lib/.
	rm -rf $(NAME_SFML)
	@echo "Finished building SFML\n-----------\n${RESET}"

clean:
	@echo "${LIGHTPURPLE}\n-----------\nCleaning SFML"
	rm -f *.o
	rm -rf *.gc*
	rm -rf tests/*.gc*
	@echo "Finished cleaning SFML\n-----------\n${RESET}"

fclean:	clean
	@rm -rf $(NAME_SFML)

re : fclean all

all: build_sfml