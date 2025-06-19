#include "so_long.h"

t_ctx *ctx_init(char *map_name)
{
	t_ctx *ctx;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
		exit_with_err(ENOMEM);
	ctx->map = parse_map(map_name);
	if (!ctx->map)
		exit(1);
	return ctx;

}


int main(int argc, char **args)
{
	t_ctx *ctx;

	if (argc < 2)
		exit_with_err(EINVAL);
	ctx = ctx_init(args[1]);
	ctx->mlx = mlx_init(ctx->map->width, ctx->map->height, args[0], true);
	if (!initialize_player(ctx))
		exit(1);
	if (!load_textures(ctx))
		exit(errno);
	draw_map(ctx);
	mlx_key_hook(ctx->mlx, handle_player_movement, ctx);
	mlx_loop_hook(ctx->mlx, collect, ctx);
	mlx_loop(ctx->mlx);
	return 0;
}