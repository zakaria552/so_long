#include "so_long.h"

bool valid_path_exists(t_map *map, t_player *player)
{
	t_list *path;
	t_vec2 target;
	int x;
	int y;

	x = y = -1;
	while (map->grid[++y])
	{
		x = -1;
		while (map->grid[y][++x])
		{
			if (map->grid[y][x] != '1' && map->grid[y][x] != '0' && map->grid[y][x] != 'P')
			{
				target.x = x;
				target.y = y;
				path = dfs_target(map, map->bounds, *player->pos, target);
				if (!path)
				{
					ft_printf("Error: Invalid map : no path leading to %c(%d, %d)", map->grid[y][x], x, y);
					ft_lstclear(&path, free);
					return false;	
				}
				ft_lstclear(&path, free);
			}
		}
	}
	ft_lstclear(&path, free);
	return true;
}

