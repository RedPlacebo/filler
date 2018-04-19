NAME = players/ikarishe.filler

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HDDIRS = fillit.h

SRC = main.c ft_read.c ft_play.c ft_try_place.c ft_free.c ft_put_move.c ft_get_strength.c analyze_boards.c read_loop.c ft_check_char.c get_strength.c

LIB = Libft_Final/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C Libft_Final/
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
