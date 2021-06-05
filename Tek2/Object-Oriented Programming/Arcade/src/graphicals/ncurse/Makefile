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

NAME_NCURSES =		arcade_ncurses.so

SRC_NCURSES	=	main_ncurses.cpp\
				../../UtilityClasses/Vector2i.cpp\
				../../UtilityClasses/Vector3i.cpp\
				../../UtilityClasses/Settings.cpp\
				../../UtilityClasses/Leaderboard.cpp\
				ncurses.cpp\
				ascii_alphabet.cpp\

build_ncurses:
	@echo "${PURPLE}\n-----------\nBuilding NCurses"
	$(CC) -c $(SRC_NCURSES) -I./../../../include -fPIC -lncurses
	$(CC) -shared *.o -o $(NAME_NCURSES) -lncurses
	cp $(NAME_NCURSES) ../../../lib/.
	rm -rf $(NAME_NCURSES)
	@echo "Finished building NCurses\n-----------\n${RESET}"

clean:
	@echo "${PURPLE}\n-----------\nCleaning NCurses"
	rm -rf *.o
	rm -rf *.gc*
	rm -rf tests/*.gc*
	@echo "Finished cleaning NCurses\n-----------\n${RESET}"

fclean: clean
	@rm -rf $(NAME_NCURSES)

re : fclean all

all: build_ncurses
