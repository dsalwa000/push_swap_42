CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = push_swap.a
NAME = push_swap
SRC = push_swap.c
OBJ = $(SRC:.c=.o)
MAIN = main.c

all: $(OBJ)
	make -C libft
	ar rcs $(AR) $(OBJ)
	$(CC) $(CFLAGS) $(MAIN) $(AR) -o $(NAME)

libft:
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(AR)

re: fclean all