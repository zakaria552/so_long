/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persue.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:42:28 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/15 16:56:39 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	stay_alert(t_ctx *ctx)
{
	const t_vec2	*pos = ctx->player->pos;
	const t_vec2	epos = ctx->enemy->pos;
	int				size;
	const int		d = ((pos->x - epos.x) * (pos->x - epos.x)) + ((pos->y
				- epos.y) * (pos->y - epos.y));

	size = ctx->map->size;
	if (d < 150 * 150)
	{
		ctx->enemy->dir = IDLE;
		ft_lstclear(&ctx->enemy->path, free);
		ctx->enemy->path = bfs_target(ctx, target_vec(epos.x / size, epos.y
					/ size), target_vec(pos->x / size, pos->y / size));
		if (ctx->enemy->path)
		{
			ctx->enemy->persuing = true;
			ctx->enemy->speed = 2;
		}
	}
	return ;
}
