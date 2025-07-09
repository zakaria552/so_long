/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:41:11 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/09 14:04:16 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	enqueue_next_adj(t_list **q, int bounds[2], int **visited,
				char **grid);

t_list	*dfs_target(t_map *map, int bounds[2], t_vec2 start, t_vec2 target)
{
	t_list	*q;
	int		**visited;
	t_vec2	*begin;

	begin = malloc(sizeof(t_vec2));
	begin->x = start.x;
	begin->y = start.y;
	visited = initialize_visited(bounds[0], bounds[1]);
	if (!visited)
		return (NULL);
	q = ft_lstnew(begin);
	visited[start.y][start.x] = 1;
	print_visit(visited, bounds[0], bounds[1]);
	while (ft_lstsize(q) > 0)
	{
		if (((t_vec2 *)q->content)->x == target.x
			&& ((t_vec2 *)q->content)->y == target.y)
			break ;
		enqueue_next_adj(&q, bounds, visited, map->grid);
	}
	free_visited(visited, bounds[0], bounds[1]);
	return (q);
}

static void	enqueue_next_adj(t_list **q, int bounds[2], int **visited,
		char **grid)
{
	const int		dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
	t_vec2			*adj;
	t_list			*to_q;
	int				i;
	t_list			*tmp;

	adj = malloc(sizeof(t_vec2));
	if (!adj)
		return ;
	i = -1;
	while (++i < 4)
	{
		adj->x = ((t_vec2 *)(*q)->content)->x + dir[i][0];
		adj->y = ((t_vec2 *)(*q)->content)->y + dir[i][1];
		if (grid[adj->y][adj->x] == '1' || !is_valid_adj(q, adj, bounds,
				visited))
		{
			if (i == 3)
			{
				tmp = *q;
				*q = (*q)->next;
				ft_lstdelone(tmp, free);
				free(adj);
			}
			continue ;
		}
		to_q = ft_lstnew(adj);
		if (!to_q)
		{
			free(adj);
			return ;
		}
		ft_lstadd_front(q, to_q);
		visited[adj->y][adj->x] = 1;
		break ;
	}
}
