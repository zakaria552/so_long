/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:47:26 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/01 14:49:52 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hooks(mlx_key_data_t keydata, t_ctx *ctx)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(ctx->mlx);
}

void	endgame(t_ctx *ctx)
{
	const offsets[2][2] = {{40, 40}, {40, 40}};
	if (ctx->state->exited)
		mlx_close_window(ctx->mlx);
	if (!ctx->state->ready_to_exit)
		return ;
	if (!ctx->map->tiles->doors[1].img->instances[0].enabled)
	{
		ctx->map->tiles->doors[1].img->instances[0].enabled = true;
		ctx->map->tiles->doors[0].img->instances[0].enabled = false;
	}
	if (check_collision(ctx, 'E', offsets))
		ctx->state->exited = true;
}

void	hooks(t_ctx *ctx)
{
	collect(ctx);
	endgame(ctx);
}

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
	mlx_loop_hook(ctx->mlx, move_hook, ctx);
	mlx_loop_hook(ctx->mlx, hooks, ctx);
	mlx_loop_hook(ctx->mlx, update_vision, ctx);
	mlx_key_hook(ctx->mlx, key_hooks, ctx);
	mlx_loop(ctx->mlx);
	ft_printf("Freeing....");
	clean_up(ctx);
	return (0);
}
