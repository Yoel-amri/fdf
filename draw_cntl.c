/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cntl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <yel-amri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 22:49:52 by mobouzar          #+#    #+#             */
/*   Updated: 2019/10/18 19:02:59 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fulldraw_helper(t_map *map, int x, int y)
{
	t_point p;

	while (x < map->x_m)
	{
		y = 0;
		while (y < map->y_m - 1)
		{
			if (map->cords[y][x].z - map->cords[y + 1][x].z != 0)
				map->color = 0xffa500;
			else if (map->cords[y][x].z > 0 &&
			(map->cords[y][x].z - map->cords[y + 1][x].z == 0))
				map->color = 0xFF0000;
			p.x0 = map->cords[y][x].x;
			p.y0 = map->cords[y][x].y;
			p.x1 = map->cords[y + 1][x].x;
			p.y1 = map->cords[y + 1][x].y;
			draw(p, map);
			y++;
		}
		x++;
	}
	menu(map);
}

void	fulldraw(t_map *map, int x, int y)
{
	t_point p;

	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	while (y < map->y_m)
	{
		x = 0;
		while (x < map->x_m - 1)
		{
			if (map->cords[y][x].z - map->cords[y][x + 1].z != 0)
				map->color = 0xffa500;
			else if (map->cords[y][x].z > 0 &&
			(map->cords[y][x].z - map->cords[y][x + 1].z == 0))
				map->color = 0xFF0000;
			p.x0 = map->cords[y][x].x;
			p.y0 = map->cords[y][x].y;
			p.x1 = map->cords[y][x + 1].x;
			p.y1 = map->cords[y][x + 1].y;
			draw(p, map);
			x++;
		}
		y++;
	}
	fulldraw_helper(map, 0, 0);
}

void	free_map(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < map->y_m)
	{
		free(map->tab[y]);
		free(map->cords[y]);
		y++;
	}
	exit(1);
}

void	key_press_helper(int keycode, t_map *map)
{
	if (keycode == 124 && map->projection == 1)
	{
		map->xplus += 10;
		map->yplus -= 10;
	}
	else if (keycode == 0)
		map->angle += 0.017453;
	else if (keycode == 1)
		map->angle -= 0.017453;
	else if (keycode == 126 && map->projection == 0)
		map->yplus -= 10;
	else if (keycode == 125 && map->projection == 0)
		map->yplus += 10;
	else if (keycode == 123 && map->projection == 0)
		map->xplus -= 10;
	else if (keycode == 124 && map->projection == 0)
		map->xplus += 10;
	else if (keycode == 6 && map->projection == 1)
		map->height += 3;
	else if (keycode == 7)
		map->height -= 3;
	else if (keycode == 53)
		free_map(map);
	fill_cords(map);
	fulldraw(map, 0, 0);
}

int		key_press(int keycode, t_map *map)
{
	if (keycode == 18)
		map->projection = 1;
	else if (keycode == 19)
		map->projection = 0;
	else if (keycode == 27)
		map->zoom -= 3;
	else if (keycode == 24)
		map->zoom += 3;
	else if (keycode == 126 && map->projection == 1)
	{
		map->yplus -= 10;
		map->xplus -= 10;
	}
	else if (keycode == 125 && map->projection == 1)
	{
		map->yplus += 10;
		map->xplus += 10;
	}
	else if (keycode == 123 && map->projection == 1)
	{
		map->xplus -= 10;
		map->yplus += 10;
	}
	key_press_helper(keycode, map);
	return (1);
}
