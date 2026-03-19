# Makefile for so_long

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_LINKING = -lmlx -lXext -lX11 -lm -lz
INCLUDE_MLX_HEADERS = -I/usr/include -Ilibft
SOURCES = so_long.c \
		parse_map.c \
		is_map_valid.c \
		valid_path.c \
		error.c \
		open_images.c \
		put_images.c \
		close_images.c \
		moves.c \
OBJFILES = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJFILES)
	@make -C libft bonus
	$(CC) $(CFLAGS) $(OBJFILES) $(MLX_LINKING) libft/libft.a -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE_MLX_HEADERS) -c $< -o $@

clean:
	rm -f $(OBJFILES)
	@make -C libft clean

fclean:clean
	rm -f $(NAME)
	@make -C libft fclean

re:fclean all

.PHONY: all clean fclean re
