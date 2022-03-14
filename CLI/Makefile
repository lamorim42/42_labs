#Name
NAME	= my_cli

### Compilation configuration
INCLUDE = ./include/
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g3

SRC		=	cli.c \
			cli_printf.c \
			cli_utils.c \

OBJ		= $(SRC:.c=.o)
OBJ_DIR	= $(addprefix obj/, $(OBJ))

VPATH	= src

### Extra configurations
RM		= rm -f

### Default goal
.DEFAULT_GOAL	= all

obj/%.o:	%.c
		$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

all:	../$(NAME)

../$(NAME):	$(OBJ_DIR)
			$(CC) $(CFLAGS) $(OBJ_DIR) -o ../$(NAME) -I $(INCLUDE)

clean:
		$(RM) $(OBJ_DIR)

fclean:	clean
		$(RM) ../$(NAME)

re:	fclean all

.PHONY	= all clean fclean re