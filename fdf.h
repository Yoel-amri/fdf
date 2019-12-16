/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 00:01:41 by mobouzar          #+#    #+#             */
/*   Updated: 2019/09/30 01:52:19 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct	s_point
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_point;

typedef struct	s_cord
{
	int			x;
	int			y;
	int			z;
}				t_cord;

typedef struct	s_draw_var
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_draw_var;

typedef struct	s_map
{
	double		angle;
	int			error;
	int			color;
	int			zoom;
	int			height;
	int			xplus;
	int			yplus;
	int			projection;
	int			x_m;
	int			y_m;
	int			**tab;
	void		*mlx_ptr;
	void		*win_ptr;
	int			margex;
	t_cord		**cords;
}				t_map;

void			ft_free(char **tab);
int				**allocate(int i, int j, t_map *map);
int				**read_map(int fd, t_map *map);
void			draw(t_point p, t_map *map);
void			iso(int *x, int *y, int z, t_map *map);
int				**fill_tab(t_map *map, int fd, int **tab);
void			fulldraw(t_map *map, int x, int y);
int				key_press(int keycode, t_map *param);
void			fill_cords(t_map *map);
void			menu(t_map *map);
void			fulldraw(t_map *map, int x, int y);
int				key_press(int keycode, t_map *map);
void			free_exit(t_map *map, int j);

#endif
