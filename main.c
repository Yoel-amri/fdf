/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 21:43:13 by mobouzar          #+#    #+#             */
/*   Updated: 2019/09/29 22:08:06 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_map *map)
{
	map->margex = 50;
	map->projection = 1;
	map->zoom = 10;
	map->xplus = 1450;
	map->yplus = -100;
	map->height = 1;
	map->color = 0xFFFFFF;
	map->error = 0;
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
				iso(&map->cords[y][x].x, &map->cords[y][x].y,
				map->cords[y][x].z * map->height);
			x++;
		}
		y++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	init(&map);
	fd = open(argv[1], O_RDWR);
	if (argc != 2 || fd == -1 || map.error == 1)
	{
		ft_putendl("ERROR");
		return (0);
	}
	map.tab = read_map(fd, &map);
	close(fd);
	fd = open(argv[1], O_RDWR);
	map.tab = fill_tab(fd, map.tab);
	fill_cords(&map);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, 5000, 2760, "FDF");
	mlx_hook(map.win_ptr, 2, 1, key_press, &map);
	fulldraw(&map, 0, 0);
	mlx_loop(map.mlx_ptr);
}
