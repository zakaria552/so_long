/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:00:06 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/16 13:39:02 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_up(t_ctx *ctx)
{
	if (!ctx)
		return ;
	free_map(ctx->map, ctx->mlx);
	free_player(ctx->player);
	if (ctx->mlx)
		mlx_terminate(ctx->mlx);
	if (ctx->state)
		free(ctx->state);
	free(ctx);
}
