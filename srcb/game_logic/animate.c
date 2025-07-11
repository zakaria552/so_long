/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:19:39 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/11 20:54:21 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_types.h"

static void	disable_images(t_asset *sprites[5], t_dir dir, int i);
static void	animate(t_asset *sprites[5], t_asset *img, t_animation_info *info,
				t_dir dir);

void	animate_player(t_ctx *ctx)
{
	t_asset		*img; 
	t_animation_info	*info;

	img = ctx->player->sprites[ctx->player->dir];
	info = ctx->player->ani_info;
	animate(ctx->player->sprites, img, info, ctx->player->dir);
}

void	animate_enemy(t_ctx *ctx)
{
	t_asset		*img; 
	t_animation_info	*info;

	img = ctx->enemy->sprites[ctx->enemy->dir];
	info = &(ctx->enemy->ani_info);
	animate(ctx->enemy->sprites, img, info, ctx->enemy->dir);
}

static void	disable_images(t_asset *sprites[5], t_dir dir, int i)
{
	int	j;

	j = -1;
	while (++j < 5)
	{
		if ((int)dir != j)
			sprites[j][i].img->enabled = false;
	}
}

static void	animate(t_asset *sprites[5], t_asset *img, t_animation_info *info,
		t_dir dir)
{
	int		i;
	double	dt;

	dt = mlx_get_time() - info->lt;
	i = -1;
	if ((dt > 0.07 && dir != IDLE) || dt > 0.25)
	{
		while (++i < 5)
		{
			if (i == info->frame_index)
				info->frame = i;
			img[i].img->enabled = (i == info->frame_index);
			disable_images(sprites, dir, i);
		}
		info->frame_index += 1;
		if (info->frame_index == 5)
			info->frame_index = 0;
		info->lt = mlx_get_time();
	}
}

