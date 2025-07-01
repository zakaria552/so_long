/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:50:49 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/01 15:53:35 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_in_bound(int bounds[2], t_vec2 *adj);

bool	is_valid_adj(t_list **q, t_vec2 *adj, int bounds[2], int **visited)
{
	if (!is_in_bound(bounds, adj))
	{
		ft_printf("out of bound/ (x:%d, y:%d)\n", adj->x, adj->y);
		print_visit(visited, bounds[0], bounds[1]);
		return (false);
	}
	if (visited[adj->y][adj->x])
	{
		ft_printf("visited (x:%d, y:%d)\n", adj->x, adj->y);
		print_visit(visited, bounds[0], bounds[1]);
		return (false);
	}
	return (true);
}

void	print_visit(int **visited, int w, int h)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	ft_printf("\n");
	while (++y < h)
	{
		x = -1;
		while (++x < w)
		{
			ft_printf("%d", visited[y][x]);
		}
		ft_printf("\n");
	}
}

int	**initialize_visited(int w, int h)
{
	int	**visited;
	int	x;
	int	y;

	visited = malloc(sizeof(int *) * h);
	x = -1;
	y = -1;
	while (++y < h)
	{
		visited[y] = calloc(w, sizeof(int));
	}
	return (visited);
}

void	free_visited(int **visited, int w, int h)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < h)
	{
		free(visited[y]);
	}
	free(visited);
}

static bool	is_in_bound(int bounds[2], t_vec2 *adj)
{
	if (adj->x < 1 || adj->y < 1 || adj->x >= (bounds[0] - 1)
		|| adj->y >= (bounds[1] - 1))
	{
		ft_printf("invalid (x:%d, y:%d)\n", adj->x, adj->y);
		return (false);
	}
	return (true);
}
/*
void	show_path(t_list *p)
{
	while (p)
	{
		ft_printf("(%d, %d)<---", ((t_vec2 *)p->content)->x,
			((t_vec2 *)p->content)->y);
		p = p->next;
	}
	ft_printf("\n");
}
*/
