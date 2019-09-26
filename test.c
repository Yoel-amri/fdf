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