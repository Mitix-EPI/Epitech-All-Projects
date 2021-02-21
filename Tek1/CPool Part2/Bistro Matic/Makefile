##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC	=		main.c									\
			include/my_strlen.c						\
			include/my_putchar.c 					\
			include/my_putstr.c 					\
			include/my_revstr.c 					\
			display_help.c 							\
			eval_expr_bistro.c 						\
			cpool_evalexpr_2019/eval_expr_str2.c	\
			include/my_int_to_str.c					\
			my_atoi.c								\
			cpool_infinadd_2019/add.c 				\
			cpool_infinadd_2019/count_keep.c 		\
			cpool_infinadd_2019/error.c 			\
			cpool_infinadd_2019/main_infinadd.c 	\
			cpool_infinadd_2019/my_get_bigger_nb.c 	\
			cpool_infinadd_2019/sub.c				\
			cpool_infinsub_2019/infin_sub.c			\
			include/my_putstr_error.c				\
			check_existing_charac.c					\
			multi_check.c
			#cpool_infinmult_2019/infin_mult.c

OBJ 	=	 $(SRC:.c=.o)

NAME = 		calc

all: $(NAME)

$(NAME):		$(OBJ)
			gcc -g3 -Wextra -Werror -W $(OBJ) -o $(NAME)

clean :
			rm -rf $(OBJ)

fclean :		clean
			rm -rf $(NAME)

re :			fclean all
