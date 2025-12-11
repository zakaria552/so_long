# Compiler flags
CC		:= cc
CFLAGS 	:= -g -Wall -Wextra -Werror 
VPATH := src:src/draw:src/parser:src/game_logic:src/texture_loads:src/utils

# Dependencies
LIB_DIR		:= ./lib
MLX_DIR		:= $(LIB_DIR)/MLX42
MLX_BUILD	:= $(MLX_DIR)/build/
MLX 		:= $(MLX_BUILD)/libmlx42.a
GLFW_DIR	:= $(LIB_DIR)/glfw
GLFW_BUILD	:= $(GLFW_DIR)/build
GLFW		:= $(GLFW_BUILD)/src/libglfw3.a
libft_dir = $(LIB_DIR)/libft
libft = $(libft_dir)/libft

# Source files
SRC_DRAW := draw.c draw_utils.c

SRC_PARSER := \
	io_utils.c \
	map_validator.c \
	map_validator_utils.c \
	parser.c \
	valid_path.c \
	valid_path_utils.c

SRC_GAME_LOGIC := \
	animate.c \
	collect.c \
	collision.c \
	enemy.c \
	enemy_mov_hook.c \
	hooks.c \
	path_finder_dfs.c \
	path_finder_bfs.c \
	path_finder_bfs_utils.c \
	persue.c \
	patrol.c \
	patrol_path.c \
	player.c \
	player_mov_hook.c \
	vision.c

SRC_TEXTURES := \
	enemy_textures.c \
	enemy_textures_utils.c \
	map_textures.c \
	player_textures.c \
	player_textures_utils.c \
	textures.c

SRC_UTILS := \
	clean_up.c \
	clean_up_utils.c \
	ctx_init.c \
	errors.c \
	mlx_safe_funcs.c \
	random.c

SRC := \
	main.c \
	$(SRC_DRAW) \
	$(SRC_PARSER) \
	$(SRC_GAME_LOGIC) \
	$(SRC_TEXTURES) \
	$(SRC_UTILS)

SRC_DIR := src
OBJ_DIR := obj
OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)
NAME = so_long
mlx = mlx_linux/libmlx.a
includes = -I ./include -I $(LIB_DIR)/MLX42/include/MLX42 -I $(libft_dir)

all: $(NAME)

$(NAME): $(MLX) $(GLFW) $(libft) $(OBJS)
	@echo "Building..."
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(libft) $(GLFW) -ldl -pthread -lm -o $(NAME)
	@echo "Done building"


$(libft):
	@git clone -q --depth 1 \
	--branch v1.0.0 \
	--single-branch \
	git@github.com:zakaria552/libft.git $(libft_dir) > /dev/null 2>&1
	$(MAKE) -C $(libft_dir) all

$(MLX):
	@git clone -q --depth 1 \
	--branch v2.4.1 \
	--single-branch \
	https://github.com/codam-coding-college/MLX42.git $(MLX_DIR) > /dev/null 2>&1
	@cd $(MLX_DIR) && cmake -B build > /dev/null 2>&1
	@$(MAKE) -C $(MLX_BUILD) --no-print-directory

$(GLFW):
	@git clone https://github.com/glfw/glfw.git $(GLFW_DIR)
	@cmake -S $(GLFW_DIR) -B $(GLFW_BUILD) > /dev/null 2>&1
	@make -C $(GLFW_BUILD) --no-print-directory

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(includes) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Removed objects"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(LIB_DIR)
	@echo "Removed binaries"

#valgrind  --gen-suppressions=all --suppressions=leaks.supp -s
