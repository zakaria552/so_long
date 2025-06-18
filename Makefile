CC = cc
CFLAGS = -g -Wall
CFILES = main.c map_validator.c draw_map.c player.c parser.c io_utils.c errors.c textures.c
OBJ = $(CFILES:.c=.o)
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

%.o: %.c
	$(CC) $(HEADERS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
