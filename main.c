#include "fdf.h"
#include <stdio.h>

void	ft_free(char **tab)
{
	int	i;

	i = -1;
	if (tab == NULL)
		return ;
	while (tab[++i] != NULL)
	{
		ft_strdel(&tab[i]);
		tab[i] = NULL;
	}
	ft_strdel(tab);
	tab = NULL;
}

int		**allocate(int i, int j, t_map *map)
{
	int k;
	int **tab;

	k = 0;
	tab = (int**)malloc(sizeof(int*) * j);
	map->cords = (t_cord**)malloc(sizeof(t_cord*) * j);
	while (k < j)
	{
		tab[k] = (int*)malloc(sizeof(int) * i);
		map->cords[k] = (t_cord*)malloc(sizeof(t_cord) * i);
		k++;
	}
    return (tab);
}

int		**read_map(int fd, t_map *map)
{
	char	*line;
	char	**tab;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = 0;
	while (get_next_line(fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		while (tab[i] != NULL)
			i++;
		count += i;
		ft_free(tab);
		j++;
	}
	map->x_m = i;
	map->y_m = j;
	if (count % j != 0)
	{
		ft_putstr("ERROR\n");
		exit(1);
	}
	return (allocate(i,j, map));
}

void	fill_cords(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < map->y_m)
	{
		x = 0;
		while (x < map->x_m)
		{
			map->cords[y][x].x = (x * map->zoom) + map->xplus;
			map->cords[y][x].y = (y * map->zoom) + map->yplus;
			map->cords[y][x].z = map->tab[y][x];
			if (map->projection == 1)
				iso(&map->cords[y][x].x, &map->cords[y][x].y, map->cords[y][x].z * map->height);
			x++;
		}
		y++;
	}
}

void	rotation(t_map *map)
{
	int x;
	int y;
	//double angle;

	x = 0;
	y = 0;
	//map->angle = 0.17453292519;
	while (y < map->y_m)
	{
		x = 0;
		while (x < map->x_m)
		{
			map->cords[y][x].x = (map->cords[y][x].x * cos(map->angle)) - (map->cords[y][x].y * sin(map->angle));
			map->cords[y][x].y = (map->cords[y][x].x * sin(map->angle)) + (map->cords[y][x].y * cos(map->angle));
			x++;
		}
		y++;
	}
}

int     main(int argc, char **argv)
{
    int fd;
	t_map map;

    map.margex = 50;
	map.projection = 0;
	map.zoom = 10;
	map.xplus = 1450;
	map.yplus = -100;
	map.height = 1;
	map.color = 0xFFFFFF;
	map.error = 0;
	map.angle = 0.01745329251;
    
    fd = open(argv[1], O_RDWR);
	if (argc != 2 || fd == -1)
    {
		ft_putendl("ERROR");
        return (0);
    }
    map.tab = read_map(fd, &map);
	close(fd);
    fd = open(argv[1], O_RDWR);
    map.tab = fill_tab(fd, map.tab);
	
	rotation(&map);
	fill_cords(&map);
	//rotation(&map);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, 5000, 2760, "FDF");
	mlx_hook(map.win_ptr, 2, 1, key_press, &map);
	fulldraw(&map, 0,0);
	mlx_loop(map.mlx_ptr);
}