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

NAME_PACMAN =		arcade_pacman.so

SRC_PACMAN = main_pacman.cpp\
			pacman.cpp\
			../../UtilityClasses/Vector2i.cpp\
			../../UtilityClasses/Vector2f.cpp\
			../../UtilityClasses/Vector3i.cpp\
			../../UtilityClasses/Settings.cpp\
			../../UtilityClasses/Object.cpp\
			../../UtilityClasses/Leaderboard.cpp\
			../../UtilityClasses/PacmanWalls.cpp\


build_pacman:
	@echo "${YELLOW}\n-----------\nBuilding Pacman"
	$(CC) -c $(SRC_PACMAN) -I./../../../include -fPIC
	$(CC) -shared *.o -o $(NAME_PACMAN)
	cp $(NAME_PACMAN) ../../../lib/.
	rm -rf $(NAME_PACMAN)
	@echo "Finished building Pacman\n-----------\n${RESET}"

clean:
	@echo "${YELLOW}\n-----------\nCleaning Pacman"
	rm -f *.o
	rm -rf *.gc*
	rm -rf tests/*.gc*
	@echo "Finished cleaning Pacman\n-----------\n${RESET}"

fclean: clean
	@rm -rf $(NAME_PACMAN)

re : fclean all

all: build_pacman