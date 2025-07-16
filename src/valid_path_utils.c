/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:50:49 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/16 15:48:17 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_in_bound(int bounds[2], t_vec2 *adj);

bool	is_valid_adj(t_vec2 *adj, int bounds[2], int **visited)
{
	if (!is_in_bound(bounds, adj))
		return (false);
	if (visited[adj->y][adj->x])
		return (false);
	return (true);
}

int	**initialize_visited(int w, int h)
{
	int	**visited;
	int	y;

	visited = malloc(sizeof(int *) * h);
	y = -1;
	while (++y < h)
	{
		visited[y] = calloc(w, sizeof(int));
	}
	return (visited);
}

void	free_visited(int **visited, int h)
{
	int	y;

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
		return (false);
	return (true);
}
