/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <yel-amri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 21:43:51 by mobouzar          #+#    #+#             */
/*   Updated: 2019/10/18 19:03:59 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	free_exit(t_map *map, int j)
{
	int x;

	x = 0;
	while (x < j)
	{
		if (map->tab[x])
			free(map->tab[x]);
		if (map->cords[x])
			free(map->cords[x]);
		x++;
	}
	exit(0);
}

int		**allocate(int i, int j, t_map *map)
{
	int k;
	int **tab;

	k = 0;
	tab = (int**)malloc(sizeof(int*) * j);
	if (tab == NULL)
		exit(0);
	map->cords = (t_cord**)malloc(sizeof(t_cord*) * j);
	if (map->cords == NULL)
	{
		free(tab);
		exit(1);
	}
	while (k < j)
	{
		tab[k] = (int*)malloc(sizeof(int) * i);
		map->cords[k] = (t_cord*)malloc(sizeof(t_cord) * i);
		if (tab[k] == NULL || map->cords[k] == NULL)
		{
			free_exit(map, k);
			exit(1);
		}
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

	j = 0;
	count = 0;
	while (get_next_line(fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		i = 0;
		while (tab[i] != NULL)
			i++;
		count += i;
		ft_free(tab);
		j++;
		ft_strdel(&line);
	}
	map->x_m = i;
	map->y_m = j;
	if (count % j != 0)
		map->error = 1;
	return (allocate(i, j, map));
}
