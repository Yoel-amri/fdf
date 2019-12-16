/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <yel-amri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 23:16:06 by mobouzar          #+#    #+#             */
/*   Updated: 2019/10/18 19:33:08 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_line(char **split, int **tab, int i)
{
	int j;

	j = 0;
	while (split[j] != NULL)
	{
		tab[i][j] = ft_atoi(split[j]);
		j++;
	}
}

int		**fill_tab(t_map *map, int fd, int **tab)
{
	int		i;
	int		j;
	char	*line;
	char	**split;

	i = 0;
	j = 0;
	while (get_next_line(fd, &line))
	{
		split = ft_strsplit(line, ' ');
		fill_line(split, tab, i);
		j = 0;
		while (split[j] != NULL)
		{
			ft_strdel(&split[j]);
			j++;
		}
		i++;
	}
	if (map->error == 1)
	{
		ft_putstr("herer\n");
		free_exit(map, map->y_m);
	}
	return (tab);
}

void	draw(t_point p, t_map *map)
{
	t_draw_var v;

	v.dx = abs(p.x1 - p.x0);
	v.dy = abs(p.y1 - p.y0);
	v.sx = p.x0 < p.x1 ? 1 : -1;
	v.sy = p.y0 < p.y1 ? 1 : -1;
	v.err = (v.dx > v.dy ? v.dx : -v.dy) / 2;
	while (1)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, p.x0, p.y0, map->color);
		if (p.x0 == p.x1 && p.y0 == p.y1)
			break ;
		v.e2 = v.err;
		if (v.e2 > -v.dx)
		{
			v.err -= v.dy;
			p.x0 += v.sx;
		}
		if (v.e2 < v.dy)
		{
			v.err += v.dx;
			p.y0 += v.sy;
		}
	}
	map->color = 0xFFFFFF;
}

void	iso(int *x, int *y, int z, t_map *map)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(map->angle);
	*y = -z + (previous_x + previous_y) * sin(map->angle);
}
