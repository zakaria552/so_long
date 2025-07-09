#include "so_long.h"

void	load_enemy(t_ctx *ctx)
{
	const char	*src[] = {"./textures/player/idle/1.png", "./textures/player/idle/2.png",
		"./textures/player/idle/3.png", "./textures/player/idle/4.png", "./textures/player/idle/5.png",NULL};
	int			i;

	ctx->enemy->idle = malloc(sizeof(t_asset) * 5);
	if (!ctx->enemy->idle)
		clean_exit(ctx, "Failed to load assets", errno);
	ft_printf("Reached here");
	i = -1;
	init_assets(ctx->enemy->idle, 5);
	while (src[++i])
	{
		ctx->enemy->idle[i].txt = mlx_load_png(src[i]);
		if (!ctx->enemy->idle[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		ctx->enemy->idle[i].img = mlx_texture_to_image(ctx->mlx,
				ctx->enemy->idle[i].txt);
		if (!ctx->enemy->idle[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(ctx->enemy->idle[i].img, 48, 48);
	}
	ft_printf("Loaded \n");
}