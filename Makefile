##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC    =	src/minishell/minishell.c 		\
			src/minishell/get_params.c 		\
			src/minishell/is_exec.c			\
			src/minishell/filecat.c			\

TEST_SRC    =

TEST_OBJ    =   $(TEST_SRC:.c=.o)

MAIN_SRC    =    src/main.c                \

MAIN_OBJ    =    $(MAIN_SRC:.c=.o)        \

OBJ    =    $(SRC:.c=.o)

NAME    =    mysh

LDLIB    =    -lmy
LIBMY    = 	   lib/libmy.a

CPPFLAGS    +=    -I./include/
CFLAGS        +=
LDFLAGS        += -L ./lib

all:	$(NAME)

$(NAME):    $(OBJ) $(MAIN_OBJ) $(LIBMY)
	$(CC) -o $@ $(OBJ) $(MAIN_OBJ) $(LIB) $(LDLIB) $(LDFLAGS)

$(LIBMY):
	make -C lib/my/

unit_tests:    fclean
unit_tests:    $(LIBMY)
unit_tests:    CFLAGS    += --coverage
unit_tests:    LDFLAGS    += --coverage -lcriterion
unit_tests:		$(TEST_OBJ) $(OBJ)
	$(CC) -o $@ $(TEST_OBJ) $(OBJ) $(LIB) $(LDFLAGS)
	./$@

debug:	CPPFLAGS += -g
debug:	all
	valgrind ./$(NAME)

gcovr:
	gcovr --exclude tests
	gcovr --exclude tests --branches

clean:
	make clean -C./lib/my/
	rm -f $(OBJ) $(MAIN_OBJ)
	rm -f $(TEST_OBJ)

fclean: clean
	make fclean -C ./lib/my/
	rm -f unit_tests
	rm -f $(TEST_OBJ)
	rm -f $(NAME)
	rm -f *.gc*

re:	fclean all

.PHONY:	all clean fclean re gcovr unit_tests
