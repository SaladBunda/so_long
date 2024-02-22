SRCS= map.c util_fs.c util_functions.c get_next_line.c map_parsing.c
OBJS=$(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
# IFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = a.out

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $(NAME)

%.o.: %.c so_long.h
	$(CC) $(SRCS) -c

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all