#include "so_long.h"

void	load_player_textures(t_ctx *ctx, t_tiles *tiles)
{
	load_idle(ctx, tiles);
	load_right(ctx, tiles);
	load_down(ctx, tiles);
	load_up(ctx, tiles);
	load_left(ctx, tiles);
}
