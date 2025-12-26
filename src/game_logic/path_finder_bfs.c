/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_bfs_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:38:30 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/16 17:47:08 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool		bfs(t_ctx *ctx, t_queue *q, t_vec2 *parent, t_vec2 target);
static void		enqueue_next_adjs(t_ctx *ctx, t_queue *q, int *visited,
					t_vec2 *parent);
static t_list	*back_trace_path(t_ctx *ctx, t_vec2 *parent, t_vec2 target);
static bool		add_next_path(t_list **path, t_vec2 **curr);

t_list	*bfs_target(t_ctx *ctx, t_vec2 start, t_vec2 target)
{
	t_list	*path;
	t_queue	*q;
	t_vec2	*parent;
	t_vec2	*s;

	if (ctx->map->grid[target.y][target.x] == '1'
		|| ctx->map->grid[start.y][start.x] == '1')
		return (NULL);
	path = NULL;
	parent = init_parent(ctx, ctx->map->bounds[0] * ctx->map->bounds[1]);
	s = malloc(sizeof(t_vec2));
	if (!s && clean_bfs(NULL, parent, NULL, NULL))
		clean_exit(ctx, NULL, errno);
	s->x = start.x;
	s->y = start.y;
	q = init_queue(s);
	if (!q && clean_bfs(NULL, parent, NULL, s))
		clean_exit(ctx, NULL, errno);
	if (bfs(ctx, q, parent, target))
		path = back_trace_path(ctx, parent, target);
	clean_bfs(q, parent, NULL, NULL);
	return (path);
}

static bool	bfs(t_ctx *ctx, t_queue *q, t_vec2 *parent, t_vec2 target)
{
	int		*visited;
	t_vec2	*curr;

	visited = malloc(sizeof(int) * ctx->map->bounds[0] * ctx->map->bounds[1]);
	if (!visited)
		return (false);
	ft_memset(visited, 0, sizeof(int) * ctx->map->bounds[0]
		* ctx->map->bounds[1]);
	while (q->head)
	{
		curr = (t_vec2 *)(q->head->content);
		visited[to_index(curr->x, curr->y, ctx->map->bounds[1])] = 1;
		if (curr->x == target.x && curr->y == target.y)
		{
			free(visited);
			return (true);
		}
		enqueue_next_adjs(ctx, q, visited, parent);
		dequeue(q, free);
	}
	free(visited);
	return (false);
}

static void	enqueue_next_adjs(t_ctx *ctx, t_queue *q, int *visited,
		t_vec2 *parent)
{
	const int	dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
	const char	**grid = (const char **)ctx->map->grid;
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
		if (grid[adj->y][adj->x] == '1' || visited[to_index(adj->x, adj->y,
				ctx->map->bounds[1])])
		{
			free(adj);
			continue ;
		}
		update_parent(q, adj, parent, ctx->map->bounds);
		visited[to_index(adj->x, adj->y, ctx->map->bounds[1])] = 1;
		if (!enqueue(q, adj))
			clean_exit(ctx, NULL, errno);
	}
}

static bool	add_next_path(t_list **path, t_vec2 **curr)
{
	t_list	*new;

	new = ft_lstnew(*curr);
	if (!new && clean_bfs(NULL, NULL, NULL, *curr))
	{
		ft_lstclear(path, free);
		return (false);
	}
	ft_lstadd_back(path, new);
	*curr = malloc(sizeof(t_vec2));
	if (!*curr)
	{
		ft_lstclear(path, free);
		return (false);
	}
	return (true);
}

static t_list	*back_trace_path(t_ctx *ctx, t_vec2 *parent, t_vec2 target)
{
	t_list	*path;
	t_vec2	*curr;
	t_vec2	*prev;

	path = NULL;
	curr = malloc(sizeof(t_vec2));
	if (!curr)
		return (NULL);
	curr->x = target.x;
	curr->y = target.y;
	prev = NULL;
	while (curr->x != -1 && curr->y != -1)
	{
		prev = curr;
		if (!add_next_path(&path, &curr))
			return (NULL);
		curr->x = parent[to_index(prev->x, prev->y, ctx->map->bounds[1])].x;
		curr->y = parent[to_index(prev->x, prev->y, ctx->map->bounds[1])].y;
	}
	free(curr);
	return (path);
}
