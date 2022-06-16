NAME = so_long
LIBFT_DIR = ./Libs/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./Libs/mlx
MLX_LIB = $(MLX_DIR)/libmlx.dylib
FLAGS = -Wall -Werror -Wextra -g -fsanitize=address
LFLAGS = -framework OpenGL -framework AppKit
INC = -I ./includes
SRC = ./src/so_long.c ./src/player_move.c ./src/move_check.c \
		./src/map.c ./src/map_check.c ./src/keyhooks.c \
		./src/image.c ./src/map_fillmap.c ./src/display.c\
		./src/Getnextline/get_next_line_utils.c \
		./src/Getnextline/get_next_line.c 

OBJ = $(SRC:%.c=%.o)

all: $(NAME)
$(NAME): $(MLX_LIB) $(LIBFT) $(OBJ)
	gcc  $(OBJ) -L. -lmlx $(LIBFT) $(LFLAGS) $(FLAGS) -o $(NAME) 

%.o: %.c
	gcc  $(INC) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)
	cd $(MLX_DIR) && cp ./libmlx.dylib ../../

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(OBJ_BONUS) libmlx.dylib

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
.PHONY: all clean fclean re bonus