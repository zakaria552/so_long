#include "so_long.h"

bool	initialize_player(t_ctx *ctx)
{
	char **grid;
	int x;
	int y;

	grid = ctx->map->grid;
	ctx->player = malloc(sizeof(t_player));
	ctx->player->pos = malloc(sizeof(t_vec2));	
	y = -1;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
		{
			if (grid[y][x] == 'P')
			{
				ctx->player->pos->x = x;
				ctx->player->pos->y = y;
				ft_printf("pos: (%d, %d)\n", ctx->player->pos->x, ctx->player->pos->y);
				return true;
			}
		}
	}
	return false;	
}

void	set_pod(t_vec2 *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}