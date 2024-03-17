SRCS= map.c util_fs.c util_functions.c get_next_line.c map_parsing.c main.c main_game.c extra_f.c
SRCB= map.c util_fs.c util_functions.c get_next_line.c map_parsing.c main.c main_game.c extra_f.c more_functions.c
DIR=./srcs/
BONUS_DIR=./bonus/
OBJS=$(patsubst %.c,$(DIR)%.o,$(SRCS)) 
OBJB=$(patsubst %.c, $(BONUS_DIR)%.o,$(SRCB))
CC = cc
CFLAGS = -Wall -Wextra -Wall -Werror -I.
# IFLAGS= -lmlx_Linux -lX11 -lXext
IFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
BONUS_NAME = so_long_bonus



all: $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJB)
	$(CC)  $^ $(IFLAGS) -o $(BONUS_NAME) 

$(NAME): $(OBJS)
	$(CC)  $^ $(IFLAGS) -o $(NAME) 

%.o: %.c so_long.h
	$(CC) $^ -c $(CFLAGS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all