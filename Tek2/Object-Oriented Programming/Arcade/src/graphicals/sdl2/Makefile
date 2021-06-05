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

NAME_SDL2 =		arcade_sdl2.so

SRC_SDL2	=	main_sdl2.cpp\
				../../UtilityClasses/Vector2i.cpp\
				../../UtilityClasses/Vector2f.cpp\
				../../UtilityClasses/Vector3i.cpp\
				../../UtilityClasses/Settings.cpp\
				../../UtilityClasses/Leaderboard.cpp\
				Text.cpp\
				Rect.cpp\
				spriteSDL.cpp\

build_sdl2:
	@echo "${RED}\n-----------\nBuilding SDL2"
	$(CC)   -c $(SRC_SDL2)  -I./../../../include -lSDL2_ttf -lSDL2 -lSDL2_image -fPIC 
	$(CC) -shared *.o $(sdl2-config --cflags --libs)-lSDL2_ttf -lSDL2_image -o $(NAME_SDL2)
	cp $(NAME_SDL2) ../../../lib/.
	rm -rf $(NAME_SDL2)
	@echo "Finished building SDL2\n-----------\n${RESET}"

clean:
	@echo "${RED}\n-----------\nCleaning SDL2"
	rm -f *.o
	rm -rf *.gc*
	rm -rf tests/*.gc*
	@echo "Finished cleaning SDL2\n-----------\n${RESET}"

fclean:	clean
	@rm -rf $(NAME_SDL2)

re : fclean all

all: build_sdl2