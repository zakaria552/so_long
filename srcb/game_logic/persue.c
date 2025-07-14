/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persue.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:42:28 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/14 23:39:23 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_list(t_list *head)
{
    while (head)
    {
        t_vec2 *vec = (t_vec2 *)head->content;  // Cast void * back to t_vec2 *
        printf("(%d, %d)<----", vec->x, vec->y);
        head = head->next;
    }
    ft_printf("\n");
}

void    stay_alert(t_ctx *ctx)
{
    const t_vec2 *pos = ctx->player->pos;
    const t_vec2 epos = ctx->enemy->pos;
    const int x = ctx->enemy->pos.x / ctx->map->size;
    const int y = ctx->enemy->pos.y / ctx->map->size;
    const int px = ctx->player->pos->x / ctx->map->size;
    const int py = ctx->player->pos->y / ctx->map->size;
    const int d = ((pos->x - epos.x) * (pos->x - epos.x)) + ((pos->y - epos.y) * (pos->y - epos.y));

    if (d < 150 * 150)
    {
        ctx->enemy->dir = IDLE;
        ft_lstclear(&ctx->enemy->path, free);
        ctx->enemy->path = bfs_target(ctx, target_vec(x, y), target_vec(px, py));
        if (ctx->enemy->path)
        {
            ctx->enemy->persuing = true;
            ctx->enemy->speed = 2;
        }
        print_list2(ctx->enemy->path);
    }
    return;
}