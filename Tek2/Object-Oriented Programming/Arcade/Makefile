##
##·EPITECH·PROJECT,·2021
##·cpp
##·File·description:
##·Makefile
##

ccred=$(echo "\033[0;31m")
ccend=$(echo "\°33[0m")

NAME = arcade

all: $(NAME)

$(NAME): graphicals games core

core:
	@echo "\e[1;34mBuilding Core$<\e[0m"
	make -C src/core

games:
	@echo "\e[1;34mBuilding Games Lib$<\e[0m"
	make -C src/games

graphicals:
	@echo "\e[1;34mBuilding Graph Lib$<\e[0m"
	make -C src/graphicals

clean:
	make clean -C src/graphicals
	make clean -C src/games
	make clean -C src/core

fclean:
	@echo "\e[1;34mCleaning project$<\e[0m"
	rm -rf arcade
	rm -rf lib/*.so
	make fclean -C src/graphicals
	make fclean -C src/games
	make fclean -C src/core

re:»    fclean all

.PHONY:»    all clean fclean re