CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = so_long
NAME_B = so_long_bonus
MLXF = -lmlx -framework OpenGL -framework AppKit

# gcc -g test.c mov_player.c coins.c game_objects.c  manage_game.c  check_errore.c check_move_to.c check_errore_to.c  map_and_free.c move_player_to.c ft_split.c ft_strdup.c get_next_line.c   -lmlx -framework OpenGL -framework AppKit   -o so_long ;./so_long

SRC = mainn.c move_player_to.c mov_player.c get_next_line.c game_objects.c \
		ft_strdup.c ft_split.c coins.c check_move_to.c check_errore.c \
		check_errore_tow.c map_and_free.c manage_game.c ft_putnbr_fd.c ft_strnstr.c\

SRC_B =  ./bonus/mainn_bonus.c ./bonus/move_player_to_bonus.c ./bonus/mov_player_bonus.c ./bonus/get_next_line_bonus.c ./bonus/game_objects_bonus.c \
		./bonus/ft_strdup_bonus.c ./bonus/ft_split_bonus.c ./bonus/coins_bonus.c ./bonus/check_move_to_bonus.c ./bonus/check_errore_bonus.c \
		./bonus/check_errore_tow_bonus.c ./bonus/map_and_free_bonus.c ./bonus/manage_game_bonus.c ./bonus/ft_putnbr_fd_bonus.c ./bonus/enemy_bonus.c\
		./bonus/ft_itoa_bonus.c  ./bonus/enemy_tow_bonus.c ./bonus/ft_strnstr_bonus.c\

OBJ = $(SRC:.c=.o)
OBJ_B =$(SRC_B:.c=.o)

all :$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(MLXF) -o $(NAME) $(OBJ)

bonus:$(NAME_B)

$(NAME_B):$(OBJ_B)
	$(CC) $(CFLAGS) $(MLXF) -o $(NAME_B) $(OBJ_B)

$(OBJ) : so_long.h
$(OBJ_B) : ./bonus/so_long_bonus.h

clean :
	$(RM) *.o
	$(RM) ./bonus/*.o 
fclean :clean
	$(RM) $(NAME) $(NAME_B)

re : fclean all

.PHONY: all bonus clean fclean re
