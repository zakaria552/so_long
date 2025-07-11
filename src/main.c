/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:47:26 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/11 17:33:40 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **args)
{
	t_ctx	*ctx;

	ctx = NULL;
	if (argc < 2)
		clean_exit(ctx, strerror(EINVAL), EINVAL);
	ctx = ctx_init(args[1]);
	initialize_player(ctx);
	if (!valid_path_exists(ctx->map, ctx->player))
		clean_exit(ctx, strerror(errno), errno);
	ctx->mlx = mlx_init(ctx->map->width, ctx->map->height, args[0], true);
	if (!ctx->mlx)
		clean_exit(ctx, NULL, errno);
	load_textures(ctx);
	draw_map(ctx);
	mlx_loop_hook(ctx->mlx, (void *) move_hook, ctx);
	mlx_loop_hook(ctx->mlx, (void *) hooks, ctx);
	mlx_loop_hook(ctx->mlx, (void *) update_vision, ctx);
	mlx_key_hook(ctx->mlx, (void *) key_hooks, ctx);
	mlx_loop(ctx->mlx);
	ft_printf("Freeing....");
	clean_up(ctx);
	return (0);
}
