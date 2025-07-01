CC = cc
CFLAGS = -g -Wall
SRC = ./src/
OBJ_DIR = ./obj/
CFILES = main.c map_validator.c draw.c valid_path.c ctx_init.c \
		valid_path_utils.c player.c clean_up.c collision.c \
 		vision.c collect.c player_mov_hook.c parser.c io_utils.c \
 		errors.c textures.c textures_utils.c path_finder.c clean_up_utils.c \
		map_validator_utils.c hooks.c mlx_safe_funcs.c
OBJ = $(addprefix $(OBJ_DIR),$(CFILES:.c=.o))
NAME = so_long
mlx = mlx_linux/libmlx.a
libft_dir = libft
libft = $(libft_dir)/libft.a
MLX = ./MLX42/build/libmlx42.a
HEADERS = -I ./include -I ./MLX42/include/MLX42 -I libft

all: $(NAME)

$(NAME): $(MLX) $(libft) $(OBJ)
	$(CC) $(CFLAGS) $(HEADERS) $(OBJ) $(MLX) $(libft) -ldl -lglfw -pthread -lm -o $@

$(libft):
	$(MAKE) -C $(libft_dir) all

$(MLX):
	git clone https://github.com/codam-coding-college/MLX42.git
	cd ./MLX42 && cmake -B build
	make -C build -j4

$(OBJ_DIR)%.o: $(SRC)%.c
	$(CC) $(HEADERS) -g $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

#valgrind --leak-check=full --show-leak-kinds=all --gen-suppressions=all --suppressions=leaks.supp -s