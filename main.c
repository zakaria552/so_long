#include "so_long.h"

int  hello(int keycode, mlx_t *mlx)
{
	ft_printf("Hello world key: %d", keycode);
	if (keycode == 27)
		//mlx_destroy_window(mlx->mlx, mlx->window);

	return 0;
}
void	clean_up(t_ctx *ctx)
{
	
}

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

void handle_player_movement(mlx_key_data_t key, t_ctx *ctx)
{

}

int main(int argc, char **args)
{
	t_ctx *ctx;

	if (argc < 2)
		exit_with_err(EINVAL);
	ctx = ctx_init(args[1]);
	ctx->mlx = mlx_init(13 * 64, 5 * 64, args[0], true);
	if (!initialize_player(ctx))
		exit(1);
	if (!load_textures(ctx))
		exit(errno);
	
	// mlx_image_t* img = mlx_texture_to_image(mlx, ctx->map->textures->empty_tile);
	// if (!img)
	// {
	// 	err_msg("Failed to turn texture to img", errno);
	// 	exit(1);	
	// }
	// if (mlx_image_to_window(mlx, img, 0, 0) < 0)
	// {
	// 	err_msg("Failed to load image to window", errno);
	// 	exit(1);
	// }

	mlx_loop_hook(ctx->mlx, draw_map, ctx);

	mlx_loop(ctx->mlx);
	// ctx->mlx->mlx = mlx_init();
	// ctx->mlx->window = mlx_new_window(ctx->mlx->mlx, 600, 600, args[0]);
	// mlx_hook(ctx->mlx->window, 2, 1L<<0, &hello, ctx);
	// mlx_loop(ctx->mlx->mlx);
	return 0;
}