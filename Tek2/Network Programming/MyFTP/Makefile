##
## EPITECH PROJECT, 2021
## my_ftp
## File description:
## Makefile
##

NAME = myftp

all: $(NAME)

$(NAME): server client

server:
	make server -C src/

client:
	make client -C src/

clean :
			make clean -C src/

fclean :	clean
			make fclean -C src/
			rm -rf myclient
			rm -rf myftp

re :		fclean	\
			all

tests_run:	$(TEST_NAME)

$(TEST_NAME):	$(SRC_TEST) $(SRC)
				gcc $(CFLAGS) $(TEST_FLAG) $(SRC) $(SRC_TEST) -o $(TEST_NAME)
				./unit_tests
				gcovr --exclude tests
				gcovr --exclude tests -b

#gcovr -r . --html --html-details -o ~/rapport.html