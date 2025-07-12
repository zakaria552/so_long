/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persue.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:42:28 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/12 23:32:41 by zfarah           ###   ########.fr       */
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
    int x = ctx->enemy->pos.x / ctx->map->size;
    int y = ctx->enemy->pos.y / ctx->map->size;
    int px = ctx->player->pos->x / ctx->map->size;
    int py = ctx->player->pos->y / ctx->map->size;
    //char **grid = ctx->map->grid;
    
    print_list(ctx->enemy->path);
    ft_printf("e(%d, %d) -- (%d, %d)", x, y, px, py);
    if ((px == x - 1 && py == y ) || (px == x + 1 && py == y) || 
        (px == x && py == y - 1) || (px == x && py == y + 1))
    {
        ft_lstclear(&ctx->enemy->path, free);
        ctx->enemy->path = dfs_target(ctx, target_vec(x, y), target_vec(px, py));
    }
    return;
}