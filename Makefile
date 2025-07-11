CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
SRCB_DIR = srcb
OBJ_DIR = obj
SRC = $(addprefix $(SRC_DIR)/, \
	clean_up.c \
	clean_up_utils.c \
	collect.c \
	collision.c \
	ctx_init.c \
	draw.c \
	errors.c \
	hooks.c \
	io_utils.c \
	main.c \
	map_validator.c \
	map_validator_utils.c \
	mlx_safe_funcs.c \
	parser.c \
	path_finder.c \
	player.c \
	player_mov_hook.c \
	textures.c \
	textures_utils.c \
	valid_path.c \
	valid_path_utils.c  \
	vision.c \
)

SRCB = $(addprefix $(SRCB_DIR)/,\
	draw/draw.c \
	draw/draw_utils.c \
	parser/io_utils.c \
	parser/map_validator.c \
	parser/map_validator_utils.c \
	parser/parser.c \
	parser/valid_path.c \
	parser/valid_path_utils.c \
	game_logic/animate.c \
	game_logic/collect.c \
	game_logic/collision.c \
	game_logic/enemy.c \
	game_logic/enemy_mov_hook.c \
	game_logic/hooks.c \
	game_logic/path_finder.c \
	game_logic/patrol.c \
	game_logic/patrol_path.c \
	game_logic/player.c \
	game_logic/player_mov_hook.c \
	game_logic/vision.c \
	texture_loads/enemy_textures.c \
	texture_loads/enemy_textures_utils.c \
	texture_loads/map_textures.c \
	texture_loads/player_textures.c \
	texture_loads/player_textures_utils.c \
	texture_loads/textures.c \
	utils/clean_up.c \
	utils/clean_up_utils.c \
	utils/ctx_init.c \
	utils/errors.c \
	utils/mlx_safe_funcs.c \
	utils/random.c \
	main.c \
)
BONUS_OBJS = $(SRCB:%.c=$(OBJ_DIR)/%.o)
OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)
NAME = so_long
mlx = mlx_linux/libmlx.a
libft_dir = libft
libft = $(libft_dir)/libft
MLX = ./MLX42/build/libmlx42.a
HEADERS = -I ./include -I ./MLX42/include/MLX42 -I libft
B_HEADERS = -I./include_bonus -I ./MLX42/include/MLX42 -I libft

all: mandatory

mandatory: $(OBJS)
	@echo "Building mandatory"
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(MLX) $(libft) -ldl -lglfw -pthread -lm -o $(NAME)
	@rm -f extras
	@touch $@
	@echo "Done building"
	
bonus: extras

extras: $(MLX) $(libft) $(BONUS_OBJS)
	@echo "Building bonus"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX) $(libft) -ldl -lglfw -pthread -lm -o $(NAME)
	@rm -f mandatory
	@touch $@
	@echo "Done building"

$(libft):
	$(MAKE) -C $(libft_dir) all

$(MLX):
	git clone https://github.com/codam-coding-college/MLX42.git
	cd ./MLX42 && cmake -B build
	make -C build -j4

$(OBJ_DIR)/$(SRCB_DIR)/%.o: $(SRCB_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(B_HEADERS) -c $< -o $@

$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/$(SRCB_DIR)
	rm -rf $(OBJ_DIR)/$(SRC_DIR)
	@rm -f mandatory
	@rm -f extras

fclean: clean
	rm -f $(NAME)

#valgrind --leak-check=full --show-leak-kinds=all --gen-suppressions=all --suppressions=leaks.supp -s