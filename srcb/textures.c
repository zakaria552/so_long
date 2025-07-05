/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:49:34 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/05 22:42:11 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_player_textures(t_ctx *ctx, t_tiles *tiles);
static void	init_textures(t_tiles *tiles);
static void	load_right(t_ctx *ctx, t_tiles *tiles);
static void	load_idle(t_ctx *ctx, t_tiles *tiles);
static void	load_right(t_ctx *ctx, t_tiles *tiles);
static void	load_left(t_ctx *ctx, t_tiles *tiles);
static void	load_up(t_ctx *ctx, t_tiles *tiles);
static void	load_down(t_ctx *ctx, t_tiles *tiles);

void	load_textures(t_ctx *ctx)
{
	t_tiles	*tiles;

	tiles = malloc(sizeof(t_tiles));
	if (!tiles)
		clean_exit(ctx, NULL, errno);
	ctx->map->tiles = tiles;
	init_textures(tiles);
	load_wall_textures(ctx, tiles);
	load_floor_textures(ctx, tiles);
	load_doors_textures(ctx, tiles);
	load_player_textures(ctx, tiles);
	load_orbs_textures(ctx, tiles);
	ft_printf("Loaded textures\n");
}

void	init_assets(t_asset *asset, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		asset[i].img = NULL;
		asset[i].txt = NULL;
	}
}

static void	load_player_textures(t_ctx *ctx, t_tiles *tiles)
{
	load_idle(ctx, tiles);
	load_right(ctx, tiles);
	load_down(ctx, tiles);
	load_up(ctx, tiles);
	load_left(ctx, tiles);
}
static void	load_idle(t_ctx *ctx, t_tiles *tiles)
{
	const char	*src[] = {"./textures/player/idle/1.png", "./textures/player/idle/2.png",
		"./textures/player/idle/3.png", "./textures/player/idle/4.png", "./textures/player/idle/5.png",NULL};
	int			i;

	tiles->idle = malloc(sizeof(t_asset) * 5);
	if (!tiles->idle)
		clean_exit(ctx, "Failed to load assets", errno);
	ft_printf("Reached here");
	i = -1;
	init_assets(tiles->idle, 5);
	while (src[++i])
	{
		tiles->idle[i].txt = mlx_load_png(src[i]);
		if (!tiles->idle[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		tiles->idle[i].img = mlx_texture_to_image(ctx->mlx,
				tiles->idle[i].txt);
		if (!tiles->idle[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(tiles->idle[i].img, 48, 48);
	}
	ft_printf("Loaded \n");
}		
static void	load_right(t_ctx *ctx, t_tiles *tiles)
{
	const char	*src[] = {"./textures/player/right/1.png", "./textures/player/right/2.png",
		"./textures/player/right/3.png", "./textures/player/right/4.png", "./textures/player/right/5.png",NULL};
	int			i;

	tiles->right = malloc(sizeof(t_asset) * 5);
	if (!tiles->right)
		clean_exit(ctx, "Failed to load assets", errno);
	ft_printf("Reached here");
	i = -1;
	init_assets(tiles->right, 5);
	while (src[++i])
	{
		tiles->right[i].txt = mlx_load_png(src[i]);
		if (!tiles->right[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		tiles->right[i].img = mlx_texture_to_image(ctx->mlx,
				tiles->right[i].txt);
		if (!tiles->right[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(tiles->right[i].img, 48, 48);
	}
	ft_printf("Loaded \n");
}		
static void	load_left(t_ctx *ctx, t_tiles *tiles)
{
	const char	*src[] = {"./textures/player/left/1.png", "./textures/player/left/2.png",
		"./textures/player/left/3.png", "./textures/player/left/4.png", "./textures/player/left/5.png",NULL};
	int			i;

	tiles->left = malloc(sizeof(t_asset) * 5);
	if (!tiles->left)
		clean_exit(ctx, "Failed to load assets", errno);
	ft_printf("Reached here");
	i = -1;
	init_assets(tiles->left, 5);
	while (src[++i])
	{
		tiles->left[i].txt = mlx_load_png(src[i]);
		if (!tiles->left[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		tiles->left[i].img = mlx_texture_to_image(ctx->mlx,
				tiles->left[i].txt);
		if (!tiles->left[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(tiles->left[i].img, 48, 48);
	}
	ft_printf("Loaded \n");
}
static void	load_up(t_ctx *ctx, t_tiles *tiles)
{
	const char	*src[] = {"./textures/player/up/1.png", "./textures/player/up/2.png",
		"./textures/player/up/3.png", "./textures/player/up/4.png", "./textures/player/up/5.png",NULL};
	int			i;

	tiles->up = malloc(sizeof(t_asset) * 5);
	if (!tiles->up)
		clean_exit(ctx, "Failed to load assets", errno);
	ft_printf("Reached here");
	i = -1;
	init_assets(tiles->up, 5);
	while (src[++i])
	{
		tiles->up[i].txt = mlx_load_png(src[i]);
		if (!tiles->up[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		tiles->up[i].img = mlx_texture_to_image(ctx->mlx,
				tiles->up[i].txt);
		if (!tiles->up[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(tiles->up[i].img, 48, 48);
	}
	ft_printf("Loaded \n");
}
static void	load_down(t_ctx *ctx, t_tiles *tiles)
{
	const char	*src[] = {"./textures/player/down/1.png", "./textures/player/down/2.png",
		"./textures/player/down/3.png", "./textures/player/down/4.png", "./textures/player/down/5.png",NULL};
	int			i;

	tiles->down = malloc(sizeof(t_asset) * 5);
	if (!tiles->down)
		clean_exit(ctx, "Failed to load assets", errno);
	ft_printf("Reached here");
	i = -1;
	init_assets(tiles->down, 5);
	while (src[++i])
	{
		tiles->down[i].txt = mlx_load_png(src[i]);
		if (!tiles->down[i].txt)
			clean_exit(ctx, "Failed to load assets", errno);
		tiles->down[i].img = mlx_texture_to_image(ctx->mlx,
				tiles->down[i].txt);
		if (!tiles->down[i].img)
			clean_exit(ctx, "Failed to load assets", errno);
		mlx_resize_image(tiles->down[i].img, 48, 48);
	}
	ft_printf("Loaded \n");
}
static void	init_textures(t_tiles *tiles)
{
	tiles->doors = NULL;
	tiles->floors = NULL;
	tiles->orbs = NULL;
	tiles->walls = NULL;
	tiles->p_idle = NULL;
}
