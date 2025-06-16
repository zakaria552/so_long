CC = cc
CFLAGS = -Wall 
CFILES = main.c map_validator.c parser.c io_utils.c errors.c
OBJ = $(CFILES:.c=.o) 
NAME = so_long
mlx = mlx_linux/libmlx.a
libft_dir = libft
libft = $(libft_dir)/libft

all: $(NAME)

$(NAME): $(OBJ) $(mlx) $(libft)
	$(CC) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $^ -o $@

$(libft): $(libft_dir) 
	make -C $^

$(mlx):
	make -C mlx_linux

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)
	make clean -C mlx_linux

