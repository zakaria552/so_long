/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_textures_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:00:25 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/17 12:47:38 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemy_idle(t_ctx *ctx)
{
	const char	*src[] = {"./textures/enemy/idle/1.png",
		"./textures/enemy/idle/2.png", "./textures/enemy/idle/3.png",
		"./textures/enemy/idle/4.png", "./textures/enemy/idle/5.png",
		NULL};
	int			i;

	ctx->enemy->idle = malloc(sizeof(t_asset) * 5);
	if (!ctx->enemy->idle)
		clean_exit(ctx, "Failed to load assets", errno);
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
}

void	load_enemy_right(t_ctx *ctx)
{
	const char	*src[] = {"./textures/enemy/right/1.png",
		"./textures/enemy/right/2.png", "./textures/enemy/right/3.png",
		"./textures/enemy/right/4.png", "./textures/enemy/right/5.png",
		NULL};
	int			i;

	ctx->enemy->right = malloc(sizeof(t_asset) * 5);
	if (!ctx->enemy->right)
		clean_exit(ctx, "Failed to load assets", errno);
	i = -1;
	init_assets(ctx->enemy->right, 5);
	while (src[++i])
	{
		ctx->enemy->right[i].txt = mlx_load_png(src[i]);
		if (!ctx->enemy->right[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		ctx->enemy->right[i].img = mlx_texture_to_image(ctx->mlx,
				ctx->enemy->right[i].txt);
		if (!ctx->enemy->right[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(ctx->enemy->right[i].img, 48, 48);
	}
}

void	load_enemy_left(t_ctx *ctx)
{
	const char	*src[] = {"./textures/enemy/left/1.png",
		"./textures/enemy/left/2.png", "./textures/enemy/left/3.png",
		"./textures/enemy/left/4.png", "./textures/enemy/left/5.png",
		NULL};
	int			i;

	ctx->enemy->left = malloc(sizeof(t_asset) * 5);
	if (!ctx->enemy->left)
		clean_exit(ctx, "Failed to load assets", errno);
	i = -1;
	init_assets(ctx->enemy->left, 5);
	while (src[++i])
	{
		ctx->enemy->left[i].txt = mlx_load_png(src[i]);
		if (!ctx->enemy->left[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		ctx->enemy->left[i].img = mlx_texture_to_image(ctx->mlx,
				ctx->enemy->left[i].txt);
		if (!ctx->enemy->left[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(ctx->enemy->left[i].img, 48, 48);
	}
}

void	load_enemy_up(t_ctx *ctx)
{
	const char	*src[] = {"./textures/enemy/up/1.png",
		"./textures/enemy/up/2.png", "./textures/enemy/up/3.png",
		"./textures/enemy/up/4.png", "./textures/enemy/up/5.png", NULL};
	int			i;

	ctx->enemy->up = malloc(sizeof(t_asset) * 5);
	if (!ctx->enemy->up)
		clean_exit(ctx, "Failed to load assets", errno);
	i = -1;
	init_assets(ctx->enemy->up, 5);
	while (src[++i])
	{
		ctx->enemy->up[i].txt = mlx_load_png(src[i]);
		if (!ctx->enemy->up[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		ctx->enemy->up[i].img = mlx_texture_to_image(ctx->mlx,
				ctx->enemy->up[i].txt);
		if (!ctx->enemy->up[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(ctx->enemy->up[i].img, 48, 48);
	}
}

void	load_enemy_down(t_ctx *ctx)
{
	const char	*src[] = {"./textures/enemy/down/1.png",
		"./textures/enemy/down/2.png", "./textures/enemy/down/3.png",
		"./textures/enemy/down/4.png", "./textures/enemy/down/5.png",
		NULL};
	int			i;

	ctx->enemy->down = malloc(sizeof(t_asset) * 5);
	if (!ctx->enemy->down)
		clean_exit(ctx, "Failed to load assets", errno);
	i = -1;
	init_assets(ctx->enemy->down, 5);
	while (src[++i])
	{
		ctx->enemy->down[i].txt = mlx_load_png(src[i]);
		if (!ctx->enemy->down[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		ctx->enemy->down[i].img = mlx_texture_to_image(ctx->mlx,
				ctx->enemy->down[i].txt);
		if (!ctx->enemy->down[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(ctx->enemy->down[i].img, 48, 48);
	}
}
