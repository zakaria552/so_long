#include "so_long.h"

int get_instance(char **grid, t_vec2 tile, char c)
{
	int i;
	int x;
	int y;

	i = x = y = -1;
	while (grid[++y])
	{
		x = -1;
		while(grid[y][++x]) 
		{
			if (grid[y][x] == c)
				i++;
			if (grid[y][x] == c && (x == tile.x && y == tile.y))
				return i;
		}
	}
	return -1;
}

void collect(t_ctx *ctx)
{
	t_vec2 tile;
	int i;

	if (ctx->state->ready_to_exit)
		return;
	ft_printf("state: %d/%d, ready_to_exit:%d\n", ctx->state->collected, ctx->state->total_orbs, ctx->state->ready_to_exit);
	tile = get_collided_tile(ctx->map, ctx->player->pos, 'C');
	if (tile.x < 0)
		return ;	
	i = get_instance(ctx->map->grid, tile, 'C');
	if (!ctx->map->tiles->coin->instances[i].enabled)
		return;
	ctx->map->tiles->coin->instances[i].enabled = false;
	ctx->state->collected += 1;
	if (ctx->state->collected == ctx->state->total_orbs)
		ctx->state->ready_to_exit = true;
}