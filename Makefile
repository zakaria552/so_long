CC = cc
CFLAGS = -g -Wall -Wextra -Werror 
SRC_DIR = src
SRCB_DIR = srcb
OBJ_DIR = obj
VPATH := srcb:srcb/draw:srcb/parser:srcb/game_logic:srcb/texture_loads:srcb/utils
MLX_PATH		:=	./MLX42/build/
MLX_BPATH		:=	./MLX42/

SRC = \
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
	vision.c

SRCB_DRAW := draw_bonus.c draw_utils_bonus.c

SRCB_PARSER := \
	io_utils_bonus.c \
	map_validator_bonus.c \
	map_validator_utils_bonus.c \
	parser_bonus.c \
	valid_path_bonus.c \
	valid_path_utils_bonus.c

SRCB_GAME_LOGIC := \
	animate_bonus.c \
	collect_bonus.c \
	collision_bonus.c \
	enemy_bonus.c \
	enemy_mov_hook_bonus.c \
	hooks_bonus.c \
	path_finder_dfs_bonus.c \
	path_finder_bfs_bonus.c \
	path_finder_bfs_utils_bonus.c \
	persue_bonus.c \
	patrol_bonus.c \
	patrol_path_bonus.c \
	player_bonus.c \
	player_mov_hook_bonus.c \
	vision_bonus.c

SRCB_TEXTURES := \
	enemy_textures_bonus.c \
	enemy_textures_utils_bonus.c \
	map_textures_bonus.c \
	player_textures_bonus.c \
	player_textures_utils_bonus.c \
	textures_bonus.c

SRCB_UTILS := \
	clean_up_bonus.c \
	clean_up_utils_bonus.c \
	ctx_init_bonus.c \
	errors_bonus.c \
	mlx_safe_funcs_bonus.c \
	random_bonus.c

SRCB := \
	main_bonus.c \
	$(SRCB_DRAW) \
	$(SRCB_PARSER) \
	$(SRCB_GAME_LOGIC) \
	$(SRCB_TEXTURES) \
	$(SRCB_UTILS)

BONUS_OBJS = $(addprefix $(OBJ_DIR)/,$(SRCB:%.c=%.o))
OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)
NAME = so_long
mlx = mlx_linux/libmlx.a
libft_dir = libft
libft = $(libft_dir)/libft
MLX = ./MLX42/build/libmlx42.a
HEADERS = -I ./include -I ./MLX42/include/MLX42 -I libft
B_HEADERS = -I./include_bonus -I ./MLX42/include/MLX42 -I libft

all: .mandatory

.mandatory: $(MLX) $(libft) $(OBJS)
	@echo "Building mandatory"
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(MLX) $(libft) -ldl -lglfw -pthread -lm -o $(NAME)
	@rm -f extras
	@touch $@
	@echo "Done building"
	
bonus: .extras

.extras: $(MLX) $(libft) $(BONUS_OBJS)
	@echo "Building bonus"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX) $(libft) -ldl -lglfw -pthread -lm -o $(NAME)
	@rm -f mandatory
	@touch $@
	@echo "Done building"

$(libft):
	@git clone -q --depth 1 \
	--branch v1.0.0 \
	--single-branch \
	git@github.com:zakaria552/libft.git > /dev/null 2>&1
	$(MAKE) -C $(libft_dir) all

$(MLX):
	@git clone -q --depth 1 \
	--branch v2.4.1 \
	--single-branch \
	https://github.com/codam-coding-college/MLX42.git > /dev/null 2>&1
	@cd $(MLX_BPATH) && cmake -B build > /dev/null 2>&1
	@$(MAKE) -C $(MLX_PATH) --no-print-directory

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(B_HEADERS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@rm -rf $(BONUS_OBJS)
	@rm -f .mandatory
	@rm -f .extras
	@echo "Removed objects"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(libft_dir)
	@rm -rf $(MLX_BPATH)
	@echo "Removed binaries"

#valgrind  --gen-suppressions=all --suppressions=leaks.supp -s