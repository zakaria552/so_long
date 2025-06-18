#include "so_long.h"


void	draw_map(t_ctx *ctx)
{
	t_tiles *tiles;
	char **grid;
	int x;
	int y;
	
	grid = ctx->map->grid;
	tiles = ctx->map->tiles;
	mlx_resize_image(tiles->wall, 64, 64);
	mlx_resize_image(tiles->empty, 64, 64);
	mlx_resize_image(tiles->coin, 64, 64);
	mlx_resize_image(tiles->player, 64, 64);
	ft_printf("Drawing map\n");
	y = -1;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
		{
			if (grid[y][x] == '1')
				mlx_image_to_window(ctx->mlx, tiles->wall, x * 64, y * 64);
			else 
				mlx_image_to_window(ctx->mlx, tiles->empty, x * 64, y * 64);
			if (grid[y][x] == 'C')
				mlx_image_to_window(ctx->mlx, tiles->coin, x * 64, y * 64);
			if (grid[y][x] == 'P')
				mlx_image_to_window(ctx->mlx, tiles->player, x * 64, y * 64);

			// break;
		}
	}
}

