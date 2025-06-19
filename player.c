#include "so_long.h"

bool	initialize_player(t_ctx *ctx)
{
	char **grid;
	int x;
	int y;

	grid = ctx->map->grid;
	ctx->player = malloc(sizeof(t_player));
	ctx->player->pos = malloc(sizeof(t_vec2));	
	ctx->player->orbs = 0;
	ctx->player->speed = 8;
	y = -1;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
		{
			if (grid[y][x] == 'P')
			{
				ctx->player->pos->x = x *ctx->map->size;
				ctx->player->pos->y = y * ctx->map->size;
				return true;
			}
		}
	}
	return false;	
}

void	set_pos(t_vec2 *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}
