#include "so_long.h"

void	load_enemy_textures(t_ctx *ctx)
{
	load_enemy_idle(ctx);
	load_enemy_down(ctx);
	load_enemy_left(ctx);
	load_enemy_right(ctx);
	load_enemy_up(ctx);
}
