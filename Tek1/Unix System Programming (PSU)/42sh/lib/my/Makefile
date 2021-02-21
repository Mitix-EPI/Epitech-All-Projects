##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for lib
##

NAME_HEADER	=	my.h

NAME_LIB	=	libmy.a

SRC	=	my_compute_power_rec.c  		\
		my_compute_square_root.c    		\
		my_evil_str.c   			\
		my_find_prime_sup.c 			\
		my_getnbr.c 				\
		my_isneg.c  				\
		my_is_prime.c   			\
		my_putchar.c    			\
		my_put_nbr.c    			\
		my_putstr.c 				\
		my_puterror.c				\
		my_revstr.c 				\
		my_showmem.c    			\
		my_showstr.c    			\
		my_show_word_array.c    		\
		my_sort_int_array.c 			\
		my_strcapitalize.c  			\
		my_strcat.c 				\
		my_strcmp.c 				\
		my_strcpy.c 				\
		my_strdup.c 				\
		my_split.c					\
		my_str_isalpha.c    			\
		my_str_islower.c    			\
		my_str_isnum.c  			\
		my_str_isprintable.c    		\
		my_str_isupper.c    			\
		my_strlen.c 				\
		my_strlowcase.c 			\
		my_strncat.c    			\
		my_strncmp.c    			\
		my_strncpy.c    			\
		my_strstr.c 				\
		my_str_to_word_array.c  		\
		my_strupcase.c  			\
		my_list_size.c				\
		my_swap.c					\
		my_memset.c					\
		my_charcat.c				\
		my_itoa.c				\
		my_base_to_dec.c			\
		my_dec_to_base.c			\
		my_realloc.c				\
		my_printf.c					\
		my_printf_funcs.c			\
		my_printf_funcs_bases.c			\
		my_printf_utils.c			\
		my_putnbr_base.c			\
		my_char_tostring.c			\
		my_split_str.c				\
		my_str_replace.c			\
		my_arr_join.c				\
		my_arr_insert.c

OBJ	=	$(SRC:.c=.o)

all:	compile lib_compile lib_copy header_copy

compile:	$(OBJ)

header_copy:
	cp $(NAME_HEADER) ../../include/my.h

lib_compile:
	ar rc $(NAME_LIB) $(OBJ)

lib_copy:
	cp $(NAME_LIB) ../

tests_run:	$(OBJ)
	gcc -o unit_tests *.c ../../tests/*.c -W -Wall -I../../include -L../ -lmy --coverage -lcriterion
	./unit_tests

clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda

fclean:
	rm -f $(NAME_LIB)
	rm -f ../$(NAME_LIB)
	rm -f ../../$(NAME_LIB)

re:	clean all
