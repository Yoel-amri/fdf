#include "fdf.h"

void    fill_line(char **split, int **tab, int i)
{
    int j;

    j = 0;
    while (split[j] != NULL)
    {
        tab[i][j] = ft_atoi(split[j]);
        j++;
    }
}

int     **fill_tab(int fd, int **tab)
{
    int     i;
    int     j;
    char    *line;
    char    **split;
    
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
    return (tab);
}

void draw(int x0, int y0, int x1, int y1, t_map *map) 
{
    int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
    int err = (dx>dy ? dx : -dy)/2, e2;

    while (1)
    {
        mlx_pixel_put(map->mlx_ptr, map->win_ptr, x0,y0, map->color);
        if (x0==x1 && y0==y1) break;
        e2 = err;
        if (e2 >-dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
    map->color = 0xFFFFFF;
}

void	iso(int *x, int *y, int z)
{
	int			previous_x;
	int			previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void    fulldraw(t_map *map, int x, int y)
{
    mlx_clear_window(map->mlx_ptr, map->win_ptr);
    while (y < map->y_m)
	{
		x = 0;
		while (x < map->x_m - 1)
		{
            if (map->cords[y][x].z - map->cords[y][x + 1].z != 0 )
                map->color = 0xffa500;
            else if (map->cords[y][x].z > 0 && (map->cords[y][x].z - map->cords[y][x + 1].z == 0))
                map->color = 0xFF0000;
			draw(map->cords[y][x].x ,map->cords[y][x].y ,map->cords[y][x + 1].x ,map->cords[y][x + 1].y ,map);
			x++;
		}
		y++;
	}
	x = 0;
	y = 0;
	while (x < map->x_m)
	{
		y = 0;
        
		while (y < map->y_m - 1)
		{
            if (map->cords[y][x].z - map->cords[y + 1][x].z != 0)
                map->color = 0xffa500;
            else if (map->cords[y][x].z > 0 && (map->cords[y][x].z - map->cords[y + 1][x].z == 0))
                map->color = 0xFF0000;
			draw(map->cords[y][x].x ,map->cords[y][x].y ,map->cords[y + 1][x].x ,map->cords[y + 1][x].y ,map);
			y++;
		}
		x++;
	}
}

void    free_map(t_map *map)
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


int     key_press(int keycode, t_map *map)
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
    else if (keycode == 124 && map->projection == 1)
    {
        map->xplus += 10;
        map->yplus -= 10;
    }
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
    fulldraw(map, 0,0);
    return (1);
}