/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:39:53 by zfarah            #+#    #+#             */
/*   Updated: 2025/07/15 23:09:48 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void		set_exit(t_map *map);
static t_map	*init_map(char *str_map);

t_map	*parse_map(char *name)
{
	t_map	*map;
	char	*str_map;

	if (!name)
		return (NULL);
	str_map = read_from_file(name);
	if (!str_map || !validate_map(name, str_map))
	{
		free(str_map);
		errno = EINVAL;
		err_msg("Invalid map", 0);
		return (NULL);
	}
	map = init_map(str_map);
	free(str_map);
	return (map);
}

static void	set_exit(t_map *map)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	map->exit = malloc(sizeof(t_vec2));
	if (!map->exit)
		return ;
	while (map->grid[++y])
	{
		x = -1;
		while (map->grid[y][++x])
		{
			if (map->grid[y][x] == 'E')
			{
				map->exit->x = x;
				map->exit->y = y;
			}
		}
	}
}

static t_map	*init_map(char *str_map)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = ft_split(str_map, '\n');
	if (!map->grid && free_map(map, NULL))
		return (NULL);
	set_exit(map);
	if (!map->exit && free_map(map, NULL))
		return (NULL);
	map->size = 64;
	map->bounds[0] = ft_strlen(map->grid[0]);
	map->bounds[1] = 0;
	while (map->grid[map->bounds[1]])
		map->bounds[1]++;
	map->width = map->bounds[0] * map->size;
	map->height = map->bounds[1] * map->size;
	return (map);
}
