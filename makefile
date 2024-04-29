CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = so_long
MLXF = -lmlx -framework OpenGL -framework AppKit

# gcc -g test.c mov_player.c coins.c game_objects.c  manage_game.c  check_errore.c check_move_to.c check_errore_to.c  map_and_free.c move_player_to.c ft_split.c ft_strdup.c get_next_line.c   -lmlx -framework OpenGL -framework AppKit   -o so_long ;./so_long

SRC = test.c move_player_to.c mov_player.c get_next_line.c game_objects.c \
		ft_strdup.c ft_split.c coins.c check_move_to.c check_errore.c \
		check_errore_tow.c map_and_free.c manage_game.c\

OBJ = $(SRC:.c=.o)

all :$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(MLXF) -o $(NAME) $(OBJ)

$(OBJ) : so_long.h

clean :
	$(RM) *.o

fclean :clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
