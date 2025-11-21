NAME = server
NAME_c = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = server.c
SRCS_c = client.c
OBJS = $(SRCS:.c=.o)
OBJS_c = $(SRCS_c:.c=.o)

all: libft $(NAME) $(NAME_c)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I. 42libft/libft.a -o $(NAME)

$(NAME_c): $(OBJS_c)
	$(CC) $(CFLAGS) $(OBJS_c) -I. 42libft/libft.a -o $(NAME_c)

libft:
	$(MAKE) -C 42libft

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_c)
	$(MAKE) -C 42libft fclean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_c)

re: fclean all

.PHONY: all clean fclean re