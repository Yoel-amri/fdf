/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 21:43:51 by mobouzar          #+#    #+#             */
/*   Updated: 2019/09/29 21:58:16 by mobouzar         ###   ########.fr       */
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
		map->error = 1;
	return (allocate(i, j, map));
}
