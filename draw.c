#include "so_long.h"

static void	draw_player(t_ctx *ctx);

void	draw_map(t_ctx *ctx)
{
	t_tiles *tiles;
	char **grid;
	int tile_size;
	int x;
	int y;
	
	grid = ctx->map->grid;
	tiles = ctx->map->tiles;
	tile_size = ctx->map->size;
	y = -1;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
		{
			if (grid[y][x] == '1')
				mlx_image_to_window(ctx->mlx, tiles->wall, x * tile_size, y * tile_size);
			else 
				mlx_image_to_window(ctx->mlx, tiles->empty, x *tile_size, y * tile_size);
			if (grid[y][x] == 'C')
				mlx_image_to_window(ctx->mlx, tiles->coin, x * tile_size, y * tile_size);
		}
	}
	draw_player(ctx);		
}

void	draw_player(t_ctx *ctx)
{
	t_tiles *tiles;
	int tile_size;
	t_vec2 *pos;
	
	tiles = ctx->map->tiles;
	tile_size = ctx->map->size;
	pos = ctx->player->pos;
	ft_printf("Drawing player (%d, %d)\n", pos->x, pos->y);
	mlx_image_to_window(ctx->mlx, tiles->player, pos->x, pos->y);
}
