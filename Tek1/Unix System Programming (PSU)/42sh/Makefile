##
## EPITECH PROJECT, 2019
## minishell2
## File description:
## minishell2 Makefile
##

MAIN	=	src/main.c

SRC	=	src/prompt.c	\
		src/initialization.c	\
		src/commands.c	\
		src/commands/cd.c	\
		src/commands/env.c	\
		src/commands/exit.c	\
		src/commands/set.c	\
		src/commands/alias.c	\
		src/environnement/initialization.c	\
		src/environnement/manipulation.c	\
		src/environnement/linked_list_utils.c	\
		src/variables/initialization.c	\
		src/variables/manipulation.c	\
		src/variables/linked_list_utils.c	\
		src/variables/vars_check.c	\
		src/aliases/aliases.c	\
		src/exec.c	\
		src/parser/parser.c	\
		src/parser/exec_redirects.c	\
		src/parser/exec_commands.c	\
		src/parser/exec_separators.c	\
		src/parser/parser_and_or.c	\
		src/tree.c	\
		src/scripting/handle_file.c \
		src/history/history.c \
		src/history/display_history.c	\
		src/history/fill_linked_list_on_start.c	\
		src/globbing/glob.c \
		src/history/move_inside_linked_list.c \
		src/ncurses/ncurses.c \
		src/ncurses/keys.c \
		src/ncurses/input.c \
		src/ncurses/erase.c \
		src/ncurses/cursor.c \
		src/ncurses/arrows.c \
		src/which/which.c	\
		src/where/where.c	\
		src/where/where_following.c	\
		src/jobs/jobs.c	\
		src/jobs/job_list.c	\
		src/jobs/fg.c	\

TESTS	=	tests/tests_where.c \
			tests/tests_history.c \
			tests/tests_node.c \
			tests/tests_alias.c \
			tests/tests_where2.c \
			tests/tests_which.c \
			tests/tests_var_checks.c \
			tests/tests_alias2.c

OBJ	=	$(MAIN:.c=.o) $(SRC:.c=.o)

OBJ_TESTS =	$(SRC:.c=.o) $(TESTS:.c=.o)

NAME	=	42sh

CC = gcc

CFLAGS	=	-W -Wall -Wextra -I./include -L./lib/ -lmy -lncurses

CFLAGS_TESTS	=	--coverage -lcriterion

CFLAGS_DEBUG = -g3

all:	lib-make compile

debug:	lib-make compile_debug

compile:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

compile_debug:	CFLAGS += $(CFLAGS_DEBUG)

compile_debug:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

lib-make:
	$(MAKE) -C lib/my/

unit_tests:	$(OBJ_TESTS)
	$(CC) -o $@ $^ $(CFLAGS) $(CFLAGS_TESTS)
	./$@

tests_run:	CFLAGS += $(CFLAGS_TESTS)

tests_run:	lib-make unit_tests

clean:
	$(RM) -f $(OBJ)
	$(RM) -f *.gcno
	$(RM) -f *.gcda
	$(RM) -f src/*.gcno
	$(RM) -f src/*.gcda
	$(RM) -f src/where/*.gcda
	$(RM) -f src/where/*.gcno
	$(RM) -f src/which/*.gcda
	$(RM) -f src/which/*.gcno
	$(RM) -f src/aliases/*.gcda
	$(RM) -f src/aliases/*.gcno
	$(RM) -f src/commands/*.gcda
	$(RM) -f src/commands/*.gcno
	$(RM) -f src/environnement/*.gcda
	$(RM) -f src/environnement/*.gcno
	$(RM) -f src/globbing/*.gcda
	$(RM) -f src/globbing/*.gcno
	$(RM) -f src/history/*.gcda
	$(RM) -f src/history/*.gcno
	$(RM) -f src/jobs/*.gcda
	$(RM) -f src/jobs/*.gcno
	$(RM) -f src/ncurses/*.gcda
	$(RM) -f src/ncurses/*.gcno
	$(RM) -f src/parser/*.gcda
	$(RM) -f src/parser/*.gcno
	$(RM) -f src/scripting/*.gcda
	$(RM) -f src/scripting/*.gcno
	$(RM) -f src/variables/*.gcda
	$(RM) -f src/variables/*.gcno
	$(RM) -f tests/*.gcno
	$(RM) -f tests/*.gcda
	$(RM) -f tests/*.o
	$(RM) -f unit_tests
	$(MAKE) clean -C lib/my/

fclean:	clean
	$(RM) -f $(NAME)

re:	fclean all
