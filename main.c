#include "fdf.h"


void    read_map(int fd)
{

}

int     main(int argc, char **argv)
{
    int fd;
    if (argc != 2)
    {
        ft_putstr("ERROR\n");
        return (0);
    }
    fd = open(argv[1], O_RDWR);
    read_map(fd);
}