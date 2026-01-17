# CC = cc
# Dla MacBooka gcc!
# Delete before evaluation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = push_swap.a
NAME = push_swap
SRC_LIBFT = libft/ft_atoi.c \
  libft/ft_bzero.c \
  libft/ft_calloc.c \
  libft/ft_isalnum.c \
  libft/ft_isalpha.c \
  libft/ft_isascii.c \
  libft/ft_isdigit.c \
  libft/ft_isprint.c \
  libft/ft_itoa.c \
  libft/ft_memchr.c \
  libft/ft_memcmp.c \
  libft/ft_memcpy.c \
  libft/ft_memmove.c \
  libft/ft_memset.c \
  libft/ft_putchar_fd.c \
  libft/ft_putendl_fd.c \
  libft/ft_putnbr_fd.c \
  libft/ft_putstr_fd.c \
  libft/ft_split.c \
  libft/ft_strchr.c \
  libft/ft_strdup.c \
  libft/ft_striteri.c \
  libft/ft_strjoin.c \
  libft/ft_strlcat.c \
  libft/ft_strlcpy.c \
  libft/ft_strlen.c \
  libft/ft_strmapi.c \
  libft/ft_strncmp.c \
  libft/ft_strnstr.c \
  libft/ft_strrchr.c \
  libft/ft_strtrim.c \
  libft/ft_substr.c \
  libft/ft_tolower.c \
  libft/ft_toupper.c
SRC_PUSH_SWAP = push_swap.c \
  fill_a.c \
  swap.c

# ONLY FOR TESTING, REMOVE!
UTILS = utils_functions.c

OBJ = $(SRC_PUSH_SWAP:.c=.o) $(SRC_LIBFT:.c=.o) $(UTILS:.c=.o)
MAIN = main.c

all: $(OBJ)
	ar rcs $(AR) $(OBJ)
	$(CC) $(CFLAGS) $(MAIN) $(AR) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(AR)

re: fclean all