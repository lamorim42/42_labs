### Name
NAME	= my_api

### Compilation configuration
INCLUDE	= ./include/
CC		= gcc
CFLAG	= -Werror -Wall -Wextra -g

CCLIB	= ar rcs

SRC		=	main.c \
			handle_db.c \
			handle_replay.c \

LIB_PATH= ./library
LIB		= mongoose.c
LIB_OBJ	= $(LIB:.c=.o)
LIB_OBJ_DIR	= $(addprefix obj/, $(LIB_OBJ))
LIB_FLAG= -L./library/ -lmongoose

OBJ		= $(SRC:.c=.o)
OBJ_DIR	= $(addprefix obj/, $(OBJ))

VPATH	= src library

### Extra configurations
RM		= rm -f

### Default goal
.DEFAULT_GOAL	= all

### Rules
obj/%.o:	%.c
			$(CC) $(CFLAG) -I $(INCLUDE) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ_DIR) $(LIB_OBJ_DIR)
			$(CCLIB) $(LIB_PATH)/libmongoose.a $(LIB_OBJ_DIR)
			$(CC) $(CFLAG) $(OBJ_DIR) $(LIB_FLAG) -lmysqlclient -o $(NAME) -I $(INCLUDE)

clean:
			$(RM) $(OBJ_DIR) $(LIB_OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIB_PATH)/libmongoose.a

re:			fclean all

.PHONY:		all clean fclean re