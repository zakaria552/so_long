#include "so_long.h"

bool check_collision(t_ctx *ctx, char c)
{
	char **grid;	
	t_vec2 *pos;
	int s;
	int x;
	int y;
	
	pos = ctx->player->pos;
	s = ctx->map->size;
	grid = ctx->map->grid;
	x = y = -1;
	while (grid[++y])	
	{
		x = -1;
		while (grid[y][++x])
		{
			if (grid[y][x] != c)
				continue;
			if (pos->x < (x * s + s) && (pos->x + 48)> (x * s) &&
				pos->y < (y*s + s) && (pos->y + 48) > (y * s) )	
				return true;
		}
	}
	return false;
}

t_vec2 get_collided_tile(t_map *map, t_vec2 *pos, char c)
{
	t_vec2 tile;
	int s;
	int x;
	int y;
	
	s = map->size;
	tile.x = tile.y = x = y = -1;
	while (map->grid[++y])	
	{
		x = -1;
		while (map->grid[y][++x])
		{
			if (map->grid[y][x] != c)
				continue;
			if (pos->x < (x * s + s) && (pos->x + 48)> (x * s) &&
				pos->y < (y*s + s) && (pos->y + 48) > (y * s) )
			{
				tile.x = x;
				tile.y = y;
				break;
			}	
		}
	}
	return tile;
}
