CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRCS = src/main.c \
       src/fonction.c

OBJS = $(SRCS:.c=.o)

NAME = fractol

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ src/libmlx_Linux.a src/libft.a src/libftprintf.a -lXext -lX11 -lm -lz

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
