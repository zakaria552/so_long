/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:00:06 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/10 21:23:23 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_enemy(t_ctx *ctx, mlx_t *mlx, t_enemy *enemy);
static void free_ui(t_ctx *ctx, t_ui *ui);

void	clean_up(t_ctx *ctx)
{
	if (!ctx)
		return ;
	free_map(ctx->map, ctx->mlx);
	free_player(ctx, ctx->player);
	free_enemy(ctx, ctx->mlx, ctx->enemy);
	free_ui(ctx, &ctx->ui);
	if (ctx->mlx)
		mlx_terminate(ctx->mlx);
	if (ctx->state)
		free(ctx->state);
	free(ctx);
}
static void free_ui(t_ctx *ctx, t_ui *ui)
{
	if (ui->steps.asset.img)
		mlx_delete_image(ctx->mlx, ui->steps.asset.img);
	if (ui->steps.str)
		free(ui->steps.str);
}
static void	free_enemy(t_ctx *ctx, mlx_t *mlx, t_enemy *enemy)
{
	if (!mlx)
		return ;
	if (!enemy)
		return;
	if (enemy->idle)
		free_assets(mlx, enemy->idle, 5);
	if (enemy->left)
		free_assets(mlx, enemy->left, 5);
	if (enemy->right)
		free_assets(mlx, enemy->right, 5);
	if (enemy->up)
		free_assets(mlx, enemy->up, 5);
	if (enemy->down)
		free_assets(mlx, enemy->down, 5);
	if (enemy->vision)
		free(enemy->vision);
	if (enemy->path)
		ft_lstclear(&enemy->path, free);
	free(ctx->enemy);
}
