#include "so_long.h"

static bool has_extension(char *name, char *ext);
static bool is_rectangular(char **map);
static bool is_enclosed(char **map);
static bool valid_char_set(char **map);

bool validate_map(char *fname, char *map)
{
	char **split;

	if (!has_extension(fname, ".ber"))
		return false;
	split = ft_split(map, '\n');
	if (!split)
		return false;
	if (!valid_char_set(split))
	{
		ft_printf("Contains/missing char set");
		free(split);
		return false;
	}
	if (!is_rectangular(split))
	{
		ft_printf("Not rectangular\n");
		free(split);
		return (false);
	}	
	if (!is_enclosed(split))
	{
		ft_printf("Not enclosed\n");
		free(split);
		return (false);
	}
	free(split);
	return (true);
}
static bool valid_char_set(char **map)
{
	int x;
	int y;
	int e;
	int p;
	int c;

	e = p = c = 0; 
	x = y = -1;
	while(map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (!ft_strchr("01CEP", map[y][x]))
				return false;
			if (map[y][x] == 'P')
				p++;	
			if (map[y][x] == 'C')
				c++;
			if (map[y][x] == 'E')
				e++;
		}
	}
	return p == 1 && c > 0 && e == 1;
}
bool is_rectangular(char **map)
{
	int w;
	int h;
	int i;

	h = w = 0;
	while (map[h])
	{
		i = 0;
		while (map[h][i])
			i++;
		if (h && i != w)
			return (false);
		w = i;
		h++;
	}
	if (h < 2 || w < 2)
		return (false);
	return (true);
}


bool has_extension(char *name, char *ext)
{
	char *last_dot;

	last_dot = ft_strrchr(name, '.');
	if (!*last_dot)
		return false;
	if (ft_strncmp(last_dot, ext, ft_strlen(ext)) == 0)
		return true;
	return false;
}

bool is_enclosed(char **map)
{
	int w;
	int h;
	int i;

	w = ft_strlen(map[0]);
	h = 0;
	while (map[h])
		h++;
	i = -1;	
	while (map[0][++i])
	{
		if (map[0][i] != '1' || map[h - 1][i] != '1')
			return false;
	}
	i = -1;
	while (++i < h && map[i][0])	
	{
		if (map[i][0] != '1' || map[i][w - 1] != '1')
			return false;
	}
	return true;
}