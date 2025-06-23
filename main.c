#include "so_long.h"

void endgame(t_ctx *ctx)
{
	if (ctx->state->exited)
		mlx_close_window(ctx->mlx);
	if (!ctx->state->ready_to_exit)
		return;
	if (!ctx->map->tiles->exit->instances[0].enabled)	
	{
		ctx->map->tiles->exit->instances[0].enabled = true;	
		ctx->map->tiles->exit_door->instances[0].enabled = false;	
	}
	if (check_collision(ctx, 'E'))
	{
		ctx->state->exited = true;
	}
}
void hooks(t_ctx *ctx)
{
	collect(ctx);
	endgame(ctx);
}

int main(int argc, char **args)
{
	t_ctx *ctx;

	ctx = NULL;
	if (argc < 2)
		clean_exit(ctx, strerror(EINVAL), EINVAL);
	ctx = ctx_init(args[1]);
	if (!initialize_player(ctx))
		clean_exit(ctx, strerror(errno), errno);
	if (!valid_path_exists(ctx->map, ctx->player))
		clean_exit(ctx, strerror(errno), errno);
	ctx->mlx = mlx_init(ctx->map->width, ctx->map->height, args[0], true);
	if (!load_textures(ctx))
		clean_exit(ctx, strerror(errno), errno);
	draw_map(ctx);
	mlx_key_hook(ctx->mlx, handle_player_movement, ctx);
	mlx_loop_hook(ctx->mlx, hooks, ctx);
	mlx_loop(ctx->mlx);
	clean_up(ctx);
	return 0;
}
