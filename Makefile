# Makefile for so_long

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXRULE = -I/usr/include -Imlx_linux -O3
LINKAPI = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
OBJFILES = $(SOURCES:.c=.o)
SOURCES = so_long.c\
	read_map.c\
	is_map_valid.c\
	valid_path.c\
	error.c\

all : $(NAME)

$(NAME) : $(OBJFILES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

%.o : %.c so_long.h
	$(CC) $(CFLAGS) $(MLXRULE) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re
