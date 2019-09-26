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

int		**allocate(int i, int j)
{
	int k;
	int **tab;

	k = 0;
	tab = (int**)malloc(sizeof(int*) * j);
	while (k < i)
	{
		tab[k] = (int*)malloc(sizeof(int) * i);
		k++;
	}
    return (tab);
}

int		**read_map(int fd)
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
		if (count != i)
			return (0);
		tab = ft_strsplit(line, ' ');
		while (tab[i] != NULL)
			i++;
		count = i;

		ft_free(tab);
		j++;
	}
	return (allocate(i,j));
}

int     main(int argc, char **argv)
{
    int fd;
	int	**tab;
    if (argc != 2)
    {
        ft_putstr("ERROR\n");
        return (0);
    }
    fd = open(argv[1], O_RDWR);
    tab = read_map(fd);
	close(fd);
    fd = open(argv[1], O_RDWR);
    tab = fill_tab(fd, tab);
    ft_putnbr(tab[0][0]);
}