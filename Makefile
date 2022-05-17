NAME	= push_swap
DIRLFT	= libft/libft.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
SRC		=  lst_split.c      move_2.c  lst_patch.c\
			lst_tiny_sort.c  move_3.c	   utils_1.c \
			lst_solve.c   parse.c	   utils_2.c \
			lst_sort.c   move_1.c	  push_swap.c
OBJ		= $(SRC:.c=.o)
INC		= -I.
LIBFT	= -L libft/. -lft
RM		= rm -f

all		: $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBFT)

.c.o	:
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY	: all clean fclean re

clean	:
	$(MAKE) clean -C libft
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(DIRLFT)
	$(RM) $(NAME)

re		: fclean
	make all
