#include "so_long.h"

static bool init_player_pos(t_ctx *ctx);

bool	initialize_player(t_ctx *ctx)
{
	ctx->player = malloc(sizeof(t_player));
	if (!ctx->player)
		return false;
	ctx->player->pos = malloc(sizeof(t_vec2));	
	if (!ctx->player->pos)
	{
		free(ctx->player);
		return NULL;
	}
	ctx->player->orbs = 0;
	ctx->player->speed = 8;
	return init_player_pos(ctx);	
}

void	set_pos(t_vec2 *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

static bool init_player_pos(t_ctx *ctx)
{
	char **grid;
	int x;
	int y;

	grid = ctx->map->grid;
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