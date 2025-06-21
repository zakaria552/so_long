#include "so_long.h"

int **initialize_visited(int w, int h)
{
	int **visited;
	int x;
	int y;
	visited = malloc(sizeof(int *) * h);
	x = y = -1;
	while (++y < h)
	{
		visited[y] = calloc(w, sizeof(int));
	}
	return visited;
}

void print_visit(int **visited, int w, int h)
{
	int x;
	int y;

	x = y = -1;
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


bool valid_path(t_map *map, t_vec2 start, t_vec2 end)
{
	t_list *q;
	int **visited;
	int rdir[4] = {0, 1, 0, -1};
	int cdir[4] = {-1, 0, 1, 0};
	int w = map->width / map->size;
	int h = map->height / map->size;
	int i;
	q = malloc(sizeof(t_list));
	visited = initialize_visited(map->width/map->size, map->height/map->size);
	q->content = &start;
	ft_printf("(%d, %d)\n", start.x, start.y);
	visited[start.y][start.x] = 1; 
	print_visit(visited, map->width / map->size, map->height/map->size);
	while (ft_lstsize(q) > 0)
	{
		t_vec2 *curr = q->content;
		if (curr->x == end.x && curr->y == end.y)
		{
			ft_printf("Found path");
			print_visit(visited, w, h);
			break;
		}
		ft_printf("Curr: (%d, %d)\n", curr->x, curr->y);
		i = -1;
		while (++i < 4)
		{
			t_vec2 *adj = malloc(sizeof(t_vec2));
			adj->x = curr->x + rdir[i];
			adj->y = curr->y + cdir[i];
			if(adj->x < 1 || adj->y < 1||
				adj->x >= (w - 1) || adj->y >= (h - 1))
			{
				ft_printf("invalid (x:%d, y:%d)\n", adj->x, adj->y);
				free(adj);
				continue;
			}
			if (map->grid[adj->y][adj->x] == '1')
			{
				free(adj);
				continue;
			}
			if (visited[adj->y][adj->x])
			{
				ft_printf("visited (x:%d, y:%d)\n", adj->x, adj->y);
				q = q->next;
				continue;
			}
			ft_lstadd_front(&q, ft_lstnew(adj));
			visited[adj->y][adj->x] = 1;
			print_visit(visited, w, h);
			break;
		}
		
	}
}
