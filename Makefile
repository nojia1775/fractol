CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRCS = src/main.c

OBJS = $(SRCS:.c=.o)

NAME = fractol

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm 

all: $(NAME)

clean: $(OBJS)
	rm -rf $^

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
