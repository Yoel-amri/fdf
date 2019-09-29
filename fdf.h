#ifndef FDF
# define FDF

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <mlx.h>
#include <math.h>

typedef struct  s_cord
{
    int         x;
    int         y;
    int         z;
}               t_cord;

typedef struct  s_map
{
    int         error;
    int         color;
    int         zoom;
    int         height;
    int         xplus;
    int         yplus;
    int         projection;
    int         x_m;
    int         y_m;
    int         **tab;
    void        *mlx_ptr;
    void        *win_ptr;
    int         margex;
    t_cord      **cords;
}               t_map;

void	ft_free(char **tab);
int		**allocate(int i, int j, t_map *map);
int		**read_map(int fd, t_map *map);
void    draw(int x0, int y0, int x1, int y1, t_map *map);
void	iso(int *x, int *y, int z);
int     **fill_tab(int fd, int **tab);
void    fulldraw(t_map *map, int x, int y);
int     key_press(int keycode, t_map *param);
void	fill_cords(t_map *map);

#endif