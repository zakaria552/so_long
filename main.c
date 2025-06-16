#include "so_long.h"

int  hello(int keycode, t_mlx_ctx *mlx)
{
	ft_printf("Hello world key: %d", keycode);
	if (keycode == 27)
		mlx_destroy_window(mlx->mlx, mlx->window);

	return 0;
}

int main(int argc, char **args)
{
	t_ctx *ctx;

	if (argc < 1)
		exit(1);	
	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
		exit_with_err(ENOMEM);
	parse_map(args[1]);
	// ctx->mlx->mlx = mlx_init();
	// ctx->mlx->window = mlx_new_window(ctx->mlx->mlx, 600, 600, args[0]);
	// mlx_hook(ctx->mlx->window, 2, 1L<<0, &hello, ctx);
	// mlx_loop(ctx->mlx->mlx);
}