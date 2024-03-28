SRCS = map.c util_fs.c util_functions.c get_next_line.c map_parsing.c main.c main_game.c extra_f.c load_textures.c
SRCB = map.c util_fs.c util_functions.c get_next_line.c map_parsing.c main.c main_game.c extra_f.c load_textures.c more_functions.c move_enemy.c
DIR = ./srcs/
BONUS_DIR = ./bonus/
OBJS = $(SRCS:%.c=$(DIR)%.o)
OBJB = $(SRCB:%.c=$(BONUS_DIR)%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
BONUS_NAME = so_long_bonus

all: $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJB) $(BONUS_DIR)so_long_bonus.h
	$(CC) $(OBJB) $(IFLAGS) -o $(BONUS_NAME)

$(NAME): $(OBJS) $(DIR)so_long.h
	$(CC) $(OBJS) $(IFLAGS) -o $(NAME)

$(DIR)%.o: $(DIR)%.c $(DIR)so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_DIR)%.o: $(BONUS_DIR)%.c $(BONUS_DIR)so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJB)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

rebonus: fclean bonus

re: fclean all
