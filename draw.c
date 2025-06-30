#include "so_long.h"
#include <math.h>

static void	draw_player(t_ctx *ctx);
static void	draw_exit(t_ctx *ctx);

void	draw_map_borders(t_ctx *ctx, t_asset *walls, int size)
{
	int x;
	int y;

	x = 0;
	y = -1;
	while(++y < ctx->map->bounds[1] - 1)
	{
		mlx_image_to_window(ctx->mlx, walls[0].img, x * size, y * size);
		mlx_image_to_window(ctx->mlx, walls[0].img, (ctx->map->bounds[0] - 1) * size, y * size);
	}
	y = 0;
	x = 0;
	while(++x < ctx->map->bounds[0] - 1)
	{
		mlx_image_to_window(ctx->mlx, walls[1].img, x * size, y * size);
		mlx_image_to_window(ctx->mlx, walls[1].img, x * size, (ctx->map->bounds[1] - 1) * size);
	}
	mlx_image_to_window(ctx->mlx, walls[1].img, 0 * size, (ctx->map->bounds[1] - 1) * size);
	mlx_image_to_window(ctx->mlx, walls[1].img, (ctx->map->bounds[0] - 1) * size, (ctx->map->bounds[1] - 1) * size);
}
void	draw_map_grid(t_ctx *ctx, t_map *map)
{
	const char **grid = (const char **)map->grid;
	const t_tiles *tiles = map->tiles;
	int x;
	int y;

	x = 0;
	y = 0;
	while (++y < map->bounds[1] - 1)
	{
		x = 0;
		while (++x < ctx->map->bounds[0] - 1)
		{
			if (grid[y][x] == '1' && grid[y+1][x] != '1')
				mlx_image_to_window(ctx->mlx, tiles->walls[1].img, x * map->size, y * map->size);
			else if (grid[y][x] == '1' && grid[y+1][x] == '1')
				mlx_image_to_window(ctx->mlx, tiles->walls[0].img, x * map->size, y * map->size);
			else 
				mlx_image_to_window(ctx->mlx, tiles->floors[(x * y) % 4].img, x * map->size, y * map->size);
			if (grid[y][x] == 'C')
				mlx_image_to_window(ctx->mlx, tiles->orbs->img, x * map->size, y * map->size);
		}
	}
}

void	draw_map(t_ctx *ctx)
{
	t_tiles *tiles;
	char **grid;
	int tile_size;
	
	grid = ctx->map->grid;
	tiles = ctx->map->tiles;
	tile_size = ctx->map->size;
	draw_map_borders(ctx, tiles->walls, tile_size);
	draw_map_grid(ctx, ctx->map);
	draw_exit(ctx);
	draw_player(ctx);		
}

void	draw_player(t_ctx *ctx)
{
	t_tiles *tiles;
	int tile_size;
	t_vec2 *pos;
	//handle failure	
	tiles = ctx->map->tiles;
	tile_size = ctx->map->size;
	pos = ctx->player->pos;
	pos->x *= ctx->map->size;
	pos->y *= ctx->map->size;
	ft_printf("Drawing player (%d, %d)\n", pos->x, pos->y);
	ctx->player->vision->img = mlx_new_image(ctx->mlx, ctx->map->width, ctx->map->height);
	mlx_image_to_window(ctx->mlx, ctx->player->vision->img, 0, 0);
	init_vision(ctx);
	mlx_image_to_window(ctx->mlx, tiles->p_idle[0].img, pos->x, pos->y);
}

void	draw_exit(t_ctx *ctx)
{
	t_tiles *tiles;
	int tile_size;
	t_vec2 *exit;
	
	tiles = ctx->map->tiles;
	tile_size = ctx->map->size;
	exit = ctx->map->exit;
	ft_printf("Drawing exit (%d, %d)\n", exit->x, exit->y);
	mlx_image_to_window(ctx->mlx, tiles->doors[1].img, exit->x * ctx->map->size, exit->y * ctx->map->size);	
	mlx_image_to_window(ctx->mlx, tiles->doors[0].img, exit->x * ctx->map->size, exit->y * ctx->map->size);	
	tiles->doors[1].img->instances[0].enabled = false;
}
