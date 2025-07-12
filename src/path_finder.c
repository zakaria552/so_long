/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:45:11 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/12 21:43:06 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dequeue(t_list **q);
static bool	enqueue_next_adj(t_list **q, int **visited, char **grid,
				t_ctx *ctx);
static void		clean_exit_dfs(t_list **q, int **visited, t_vec2 *pos, t_ctx *ctx);

t_list	*dfs_target(t_ctx *ctx, t_vec2 start, t_vec2 target)
{
	t_list	*q;
	int		**visited;
	t_vec2	*begin;

	begin = malloc(sizeof(t_vec2));
	visited = initialize_visited(ctx->map->bounds[0], ctx->map->bounds[1]);
	q = ft_lstnew(begin);
	if (!q || !visited || !begin)
		clean_exit_dfs(&q, visited, begin, ctx);
	begin->x = start.x;
	begin->y = start.y;
	visited[start.y][start.x] = 1;
	visited[start.y][start.x] = 1;
	while (ft_lstsize(q) > 0)
	{
		if (((t_vec2 *)q->content)->x == target.x
			&& ((t_vec2 *)q->content)->y == target.y)
			break ;
		if (enqueue_next_adj(&q, visited, ctx->map->grid, ctx))
			visited[((t_vec2 *)q->content)->y][((t_vec2 *)q->content)->x] = 1;
		else
			dequeue(&q);
	}
	free_visited(visited, ctx->map->bounds[1]);
	return (q);
}

static void	clean_exit_dfs(t_list **q, int **visited, t_vec2 *pos, t_ctx *ctx)
{
	if (q)
		ft_lstclear(q, free);
	if (visited)
		free_visited(visited, ctx->map->bounds[1]);
	if (pos)
		free(pos);
	clean_exit(ctx, NULL, errno);
}

static void	dequeue(t_list **q)
{
	t_list	*tmp;

	tmp = *q;
	*q = (*q)->next;
	ft_lstdelone(tmp, free);
}

static bool	enqueue_next_adj(t_list **q, int **visited, char **grid, t_ctx *ctx)
{
	const int	dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
	t_vec2		*adj;
	t_list		*to_q;
	int			i;

	adj = malloc(sizeof(t_vec2));
	if (!adj)
		clean_exit_dfs(q, visited, NULL, ctx);
	i = -1;
	while (++i < 4)
	{
		adj->x = ((t_vec2 *)(*q)->content)->x + dir[i][0];
		adj->y = ((t_vec2 *)(*q)->content)->y + dir[i][1];
		if (grid[adj->y][adj->x] == '1' || !is_valid_adj(adj, ctx->map->bounds,
				visited))
			continue ;
		to_q = ft_lstnew(adj);
		if (!to_q)
			clean_exit_dfs(q, visited, adj, ctx);
		ft_lstadd_front(q, to_q);
		return (true);
	}
	free(adj);
	return (false);
}
