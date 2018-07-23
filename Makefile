##
## EPITECH PROJECT, 2018
## MAkefile
## File description:
## file of compilation
##

NAME	= server

CC	= gcc

RM	= rm -f

SRCS	=   ./src/main.c \
	  ./src/print_help.c \
	  ./src/error_gestion.c \
	  ./src/socket_gestion.c \
	  ./src/utils_functions.c \
	  ./src/cmd_gestion.c \
	  ./src/my_str_to_wordtab.c \
	  ./src/utils_functions2.c \
	  ./src/error_file2.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./header/
CFLAGS += -W -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
