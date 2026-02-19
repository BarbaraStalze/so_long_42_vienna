# Makefile for so_long

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OBJFILES = $(SOURCES:.c=.o)
SOURCES = \

all : $(NAME)

$(NAME) : $(OBJFILES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)
#	ar rcs $(@) $(?)

%.o : %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re
