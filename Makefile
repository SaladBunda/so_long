SRCS= map.c util_fs.c util_functions.c get_next_line.c map_parsing.c main.c main_game.c
DIR=./srcs/
OBJS=$(patsubst %.c,$(DIR)%.o,$(SRCS)) 
CC = gcc
CFLAGS = -Wall -Wextra -Wall -I.
# IFLAGS= -lmlx_Linux -lX11 -lXext
IFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC)  $^ $(IFLAGS) -o $(NAME) 

%.o: %.c so_long.h
	$(CC) $(SRCS) -c $(CFLAGS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all