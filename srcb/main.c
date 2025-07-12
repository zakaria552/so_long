/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:24:44 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/12 21:05:41 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **args)
{
	t_ctx	*ctx;

	ctx = NULL;
	if (argc < 2)
		clean_exit(ctx, strerror(EINVAL), EINVAL);
	ctx = ctx_init(args[1]);
	initialize_player(ctx);
	initialize_enemy(ctx);
	if (!valid_path_exists(ctx))
		clean_exit(ctx, "Invalid map", errno);
	ctx->mlx = mlx_init(ctx->map->width, ctx->map->height, args[0], true);
	if (!ctx->mlx)
		clean_exit(ctx, NULL, errno);
	load_textures(ctx);
	draw_map(ctx);
	mlx_loop_hook(ctx->mlx, (void *) patrol, ctx);
	mlx_loop_hook(ctx->mlx, (void *) animate_player, ctx);
	mlx_loop_hook(ctx->mlx, (void *) animate_enemy, ctx);
	mlx_loop_hook(ctx->mlx, (void *) move_hook, ctx);
	mlx_loop_hook(ctx->mlx, (void *) hooks, ctx);
	mlx_loop_hook(ctx->mlx, (void *) update_vision, ctx);
	mlx_key_hook(ctx->mlx, (void *) key_hooks, ctx);
	mlx_loop(ctx->mlx);
	clean_up(ctx);
	return (0);
}
