#include "so_long.h"
void set_exit(t_map *map);

t_map *parse_map(char *name)
{
	t_map *map;
	char *str_map;

	if (!name)
		return NULL;
	ft_printf("name: %s\n", name);
	str_map = read_from_file2(name);
	ft_printf("map: \n%s\n", str_map);
	if (!str_map || !validate_map(name, str_map))	
	{
		free(str_map);
		errno = EINVAL;
		err_msg("Invalid map", 0);
		return NULL;
	}
	map = malloc(sizeof(t_map));
	if (!map)
	{
		free(str_map);
		return NULL;
	}
	map->grid = ft_split(str_map, '\n');
	if (!map->grid)
	{
		free(str_map);
		free_map(map, NULL);
		return NULL;
	}
	set_exit(map);
	if (!map->exit)
	{
		free_map(map, NULL);
		return NULL;	
	}
	map->size = 64;
	map->bounds[0] = ft_strlen(map->grid[0]);
	map->bounds[1] = 0;
	while (map->grid[map->bounds[1]])
		map->bounds[1]++;		
	map->width = map->bounds[0] * map->size;
	map->height = map->bounds[1] * map->size;
	free(str_map);
	return map;
}

void set_exit(t_map *map)
{
	int x;
	int y;
	
	x = y = -1;
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