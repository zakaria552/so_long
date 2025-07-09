#include "so_long.h"

void	load_enemy_textures(t_ctx *ctx)
{
	load_enemy_idle(ctx);
	load_enemy_down(ctx);
	load_enemy_left(ctx);
	load_enemy_right(ctx);
	load_enemy_up(ctx);
	ctx->enemy->sprites[0] = ctx->enemy->up;
	ctx->enemy->sprites[1] = ctx->enemy->down;
	ctx->enemy->sprites[2] = ctx->enemy->left;
	ctx->enemy->sprites[3] = ctx->enemy->right;
	ctx->enemy->sprites[4] = ctx->enemy->idle;
}
