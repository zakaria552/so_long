#include "so_long.h"

t_ctx *ctx_init(char *map_name)
{
	t_ctx *ctx;

	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
		clean_exit(ctx, strerror(errno), errno);
	ctx->map = NULL;
	ctx->player = NULL;	
	ctx->mlx = NULL;
	ctx->map = parse_map(map_name);
	if (!ctx->map)
		clean_exit(ctx, strerror(errno), errno);
	return ctx;
}

int main(int argc, char **args)
{
	t_ctx *ctx;
	t_list *p;
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
	mlx_loop_hook(ctx->mlx, collect, ctx);
	mlx_loop(ctx->mlx);
	return 0;
}