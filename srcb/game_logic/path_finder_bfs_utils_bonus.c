/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_bfs_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:34:40 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/15 23:09:48 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	to_index(int x, int y, int cols)
{
	return (y * cols + x);
}

t_vec2	*init_parent(t_ctx *ctx, int size)
{
	t_vec2	*parent;
	int		i;

	parent = malloc(sizeof(t_vec2) * size);
	if (!parent)
		clean_exit(ctx, NULL, errno);
	i = -1;
	while (++i < size)
	{
		parent[i].x = -1;
		parent[i].y = -1;
	}
	return (parent);
}

void	print_list2(t_list *head)
{
	t_vec2	*vec;

	while (head)
	{
		vec = (t_vec2 *)head->content;
		ft_printf("(%d, %d)<----", vec->x, vec->y);
		head = head->next;
	}
	ft_printf("\n");
}

bool	clean_bfs(t_queue *q, t_vec2 *parent, t_vec2 *visited, t_vec2 *pos)
{
	if (q)
	{
		ft_lstclear(&q->head, free);
		free(q);
	}
	if (parent)
		free(parent);
	if (visited)
		free(visited);
	return (true);
}

void	update_parent(t_queue *q, t_vec2 *adj, t_vec2 *parent, int bounds[2])
{
	int	i;

	i = to_index(adj->x, adj->y, bounds[1]);
	parent[i].x = ((t_vec2 *)(q->head->content))->x;
	parent[i].y = ((t_vec2 *)(q->head->content))->y;
}
