#include "so_long.h"

t_map *parse_map(char *name)
{
	t_map *map;
	char *str_map;

	if (!name)
		return NULL;
	ft_printf("name: %s\n", name);
	str_map = read_from_file(name);
	ft_printf("map: \n%s\n", str_map);
	if (!str_map || !validate_map(name, str_map))	
	{
		free(str_map);
		err_msg("Invalid map", 0);
		return NULL;
	}
	map = malloc(sizeof(t_map));
	map->grid = ft_split(str_map, '\n');
	map->size = 64;
	map->width = ft_strlen(map->grid[0]) * map->size;
	map->height = 0;
	while (map->grid[map->height])
		map->height++;	
	map->height = map->height * map->size;
	return map;
}
