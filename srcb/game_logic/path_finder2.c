/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:44:45 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/14 15:36:21by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool bfs(t_ctx *ctx, t_queue *q, t_vec2 parent[], t_vec2 target);
static bool	enqueue_next_adjs(t_ctx *ctx, t_queue *q, int *visited, t_vec2 parent[]);
void print_list2(t_list *head)
{
    while (head)
    {
        t_vec2 *vec = (t_vec2 *)head->content;  // Cast void * back to t_vec2 *
        ft_printf("(%d, %d)<----", vec->x, vec->y);
        head = head->next;
    }
    ft_printf("\n");
}
int to_index(int x, int y, int cols) {
    return y * cols + x;
}
t_list *trace_path(t_ctx *ctx, t_vec2 parent[], t_vec2 start, t_vec2 target)
{
    t_list *path;
    t_list *new;
    t_vec2 *curr;
    t_vec2 *prev;

    path = NULL;
    ft_printf("trace: s(%d, %d) e(%d, %d)\n", start.x, start.y, target.x, target.y);
    curr = malloc(sizeof(t_vec2));
    if (!curr)
        clean_exit(ctx, NULL, errno);
    curr->x = target.x;
    curr->y = target.y;
    while (curr->x != -1 && curr->y != -1)
    {
        new = ft_lstnew(curr);
        if (!new)
            clean_exit(ctx, NULL, errno);
        ft_lstadd_back(&path, new);
        prev = curr;
        curr = malloc(sizeof(t_vec2));
        if (!curr)
            clean_exit(ctx, NULL, errno);
        curr->x = parent[to_index(prev->x, prev->y, ctx->map->bounds[1])].x;
        curr->y = parent[to_index(prev->x, prev->y, ctx->map->bounds[1])].y;
    }
    print_list2(path);
    ft_printf("__________________________________\n");

    return path;
}

void init_parent(t_vec2 parent[], int size)
{
    int i;

    i = -1;
    while (++i < size)
    {
        parent[i].x = -1;
        parent[i].y = -1;
    }
}


t_list *bfs_target(t_ctx *ctx, t_vec2 start, t_vec2 target)
{
    t_list *path;
    t_queue *q;
    t_vec2  parent[ctx->map->bounds[0] * ctx->map->bounds[1]];
    t_vec2  *s;

    init_parent(parent, ctx->map->bounds[0] * ctx->map->bounds[1]);
    s = malloc(sizeof(t_vec2));
    s->x = start.x;
    s->y = start.y;
    q = init_queue(s);
    if (ctx->map->grid[target.y][target.x] == '1' || ctx->map->grid[start.y][start.x] == '1')
        return NULL;
    if (!q)
        clean_exit(ctx, NULL, errno);
    if (bfs(ctx, q, parent, target));
        return trace_path(ctx, parent, start, target);

    
    
}

static bool bfs(t_ctx *ctx, t_queue *q, t_vec2 parent[], t_vec2 target)
{
    int    visited[ctx->map->bounds[0] * ctx->map->bounds[1]];
    ft_printf("BOunds: %d, %d", ctx->map->bounds[0] , ctx->map->bounds[1]);
    t_vec2 *curr;

    ft_memset(visited, 0, sizeof(int) * ctx->map->bounds[0] * ctx->map->bounds[1]);
    //print_list2(q->head);
    ft_printf("----> target: %d, %d\n", target.x, target.y);
    while (q->head)
    {
        ft_printf("Loop \n");
        curr = (t_vec2 *)(q->head->content);
        visited[to_index(curr->x, curr->y, ctx->map->bounds[1])] = 1;
        ft_printf("Curr: (%d, %d)\n", curr->x, curr->y);
        if (curr->x == target.x && curr->y == target.y) 
            return true;
        enqueue_next_adjs(ctx, q, visited, parent);
        dequeue(q, free);
        ft_printf("\n");
    }
    ft_printf("Found\n");
    return false;
}

static bool	enqueue_next_adjs(t_ctx *ctx, t_queue *q, int *visited, t_vec2 parent[])
{
	const int	dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    const char **grid = ctx->map->grid;
	t_vec2		*adj;
	int			i;

	i = -1;
	while (++i < 4)
	{
	    adj = malloc(sizeof(t_vec2));
	    if (!adj)
            clean_exit(ctx, NULL, errno);
		adj->x = ((t_vec2 *)(q->head->content))->x + dir[i][0];
		adj->y = ((t_vec2 *)(q->head->content))->y + dir[i][1];
        ft_printf("adj: %c(%d, %d) index: %d\n", grid[adj->y][adj->x], adj->x, adj->y, to_index(adj->x, adj->y, ctx->map->bounds[1]));
        ft_printf("visited: %d\n", visited[to_index(adj->x, adj->y, ctx->map->bounds[1])]);
		if (grid[adj->y][adj->x] == '1' || visited[to_index(adj->x, adj->y, ctx->map->bounds[1])])
        {
            free(adj);
			continue ;
        }
        ft_printf("valid-adj: (%d, %d), index: %d\n", adj->x, adj->y, to_index(adj->x, adj->y, ctx->map->bounds[1]));
        parent[to_index(adj->x, adj->y, ctx->map->bounds[1])].x = ((t_vec2 *)(q->head->content))->x;
        parent[to_index(adj->x, adj->y, ctx->map->bounds[1])].y = ((t_vec2 *)(q->head->content))->y;
        visited[to_index(adj->x, adj->y, ctx->map->bounds[1])] = 1;
        enqueue(q, adj);
	}
	return (false);
}
