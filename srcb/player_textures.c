#include "so_long.h"

void	load_player_textures(t_ctx *ctx, t_tiles *tiles)
{
	load_idle(ctx, tiles);
	load_right(ctx, tiles);
	load_down(ctx, tiles);
	load_up(ctx, tiles);
	load_left(ctx, tiles);
	ctx->player->sprites[0] = ctx->map->tiles->up;
	ctx->player->sprites[1] = ctx->map->tiles->down;
	ctx->player->sprites[2] = ctx->map->tiles->left;
	ctx->player->sprites[3] = ctx->map->tiles->right;
	ctx->player->sprites[4] = ctx->map->tiles->idle;
}
