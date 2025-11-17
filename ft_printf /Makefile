NAME = libftprintf.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c put_vars.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re