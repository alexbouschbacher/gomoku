##
## EPITECH PROJECT, 2019
## gomoku
## File description:
## Makefile
##

CC      =   gcc

CFLAGS  =   -W -Wall -Wextra -g3 -I./include/ -lm

SRC     =   src/gomoku.c				\
			src/utils.c					\
			src/manager/manager.c		\
			src/manager/start.c			\
			src/manager/board.c			\
			src/manager/begin.c			\
			src/manager/end.c			\
			src/manager/turn.c			\
			src/manager/display.c		\
			src/ia/ia.c					\
			src/ia/ia_utils.c			\
			src/ia/get_childs.c			\
			src/ia/static_eval.c		\
			src/ia/static_eval_diag.c	\
			src/ia/static_eval_utils.c	\

SRC_TEST	=	testing/test_eval.c \
				src/ia/ia.c					\
				src/ia/ia_utils.c			\
				src/ia/get_childs.c			\
				src/ia/static_eval.c		\
				src/ia/static_eval_diag.c	\
				src/ia/static_eval_utils.c	\

OBJ     =   $(SRC:.c=.o)

NAME    =   pbrain-gomoku-ai

all:        $(NAME)

$(NAME):    $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

tests_run:
		$(CC) -o unit_tests $(SRC_TEST) --coverage -lcriterion $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm -f *.gcda *.gcno
fclean:	clean
		rm $(NAME)

re:     clean all
