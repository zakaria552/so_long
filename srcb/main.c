/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:47:26 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/05 22:43:56farah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char *dir(t_dir dir)
{
	if (dir == IDLE)
		return "idle";
	else if (dir == RIGHT)
		return "right";
	else if (dir == LEFT)
		return "right";
	else if (dir == UP)
		return "up";
	else if (dir == DOWN)
		return "down";
}
void disable_images(t_ctx *ctx, int i)
{
	if (ctx->player->dir != IDLE)
		ctx->map->tiles->idle[i].img->enabled = false;
	if (ctx->player->dir != RIGHT)
		ctx->map->tiles->right[i].img->enabled = false;
	if (ctx->player->dir != LEFT)
		ctx->map->tiles->left[i].img->enabled = false;
	if (ctx->player->dir != DOWN)
		ctx->map->tiles->down[i].img->enabled = false;
	if (ctx->player->dir != UP)
		ctx->map->tiles->up[i].img->enabled = false;
}
void	animate(t_ctx *ctx)
{
	int i;
	t_animation_info *info = ctx->player->ani_info;
	t_asset	*img = get_img_from_dir(ctx, ctx->player->dir);
	double dt = mlx_get_time() - info->lt;
	i = -1;
	printf("lt: %.2f, dt: %.2f, fi: %d\n", info->lt, dt, info->frame_index);
	ft_printf("Dir: %s", dir(ctx->player->dir));
	if (dt > 0.2)
	{
		ft_printf("Moving to next frame....\n");
		ft_printf("frame: %d, fi: %d\n", ctx->player->ani_info->frame, ctx->player->ani_info->frame_index);
		while (++i < 5)
		{
			ft_printf("i: %d\n", i);
			if ((i == info->frame_index))
				info->frame = i;
			img[i].img->enabled = (i == info->frame_index);
			disable_images(ctx, i);
		}
		info->frame_index += 1;
		if (info->frame_index == 5)
			ctx->player->ani_info->frame_index = 0;
		info->lt = mlx_get_time();
	}

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
	mlx_loop_hook(ctx->mlx, animate, ctx);
	mlx_loop_hook(ctx->mlx, move_hook, ctx);
	mlx_loop_hook(ctx->mlx, hooks, ctx);
	mlx_loop_hook(ctx->mlx, update_vision, ctx);
	mlx_key_hook(ctx->mlx, key_hooks, ctx);
	mlx_loop(ctx->mlx);
	ft_printf("Freeing....");
	clean_up(ctx);
	return (0);
}
