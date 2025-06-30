#include "so_long.h"

static void init_player_pos(t_ctx *ctx);

void initialize_player(t_ctx *ctx)
{
	ctx->player = malloc(sizeof(t_player));
	if (!ctx->player)
		clean_exit(ctx, NULL, errno);
	ctx->player->pos = malloc(sizeof(t_vec2));	
	if (!ctx->player->pos)
		clean_exit(ctx, NULL, errno);
	ctx->player->vision = malloc(sizeof(t_vision));
	if(!ctx->player->vision)
		clean_exit(ctx, NULL, errno);
	ctx->player->orbs = 0;
	ctx->player->speed = 8;
	ctx->player->vision->r = 150;
	init_player_pos(ctx);
}

static void init_player_pos(t_ctx *ctx)
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
				ctx->player->pos->x = x;
				ctx->player->pos->y = y;
				return ;
			}
		}
	}
}

