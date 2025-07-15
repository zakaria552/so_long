/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:22:36 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/15 23:09:48 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemy_textures(t_ctx *ctx)
{
	load_enemy_idle(ctx);
	load_enemy_down(ctx);
	load_enemy_left(ctx);
	load_enemy_right(ctx);
	load_enemy_up(ctx);
	ctx->enemy->sprites[0] = ctx->enemy->up;
	ctx->enemy->sprites[1] = ctx->enemy->down;
	ctx->enemy->sprites[2] = ctx->enemy->left;
	ctx->enemy->sprites[3] = ctx->enemy->right;
	ctx->enemy->sprites[4] = ctx->enemy->idle;
}
