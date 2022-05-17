NAME	= libft.a
CC		= gcc
AR		= ar rcs
CFLAGS	= -Wall -Werror -Wextra
INC		= -I includes
SRC		= ft_atoi.c	   ft_is_sort.c		ft_lstclear.c	 ft_split.c \
			ft_calloc.c	   ft_is_sort_rotate.c	ft_lstlast.c	 ft_strlen.c \
			ft_free_split.c    ft_list_at.c		ft_lstnew.c	 \
			ft_index_lst_at.c  ft_lstadd_back.c	ft_lstsize.c \
			ft_isdigit.c	   ft_lstadd_front.c	ft_putendl_fd.c
OBJ		= $(SRC:.c=.o)
RM		= rm -f

all		: $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $^

.c.o	:
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY	: all clean fclean re

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re		: fclean
	make all
