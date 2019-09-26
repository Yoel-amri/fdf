/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:18:03 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/27 19:54:50 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_line(char **save, char **line, int fd, int ret)
{
	char	*tmp;
	int		j;

	j = ft_lenc(save[fd], '\n');
	if (save[fd][j] == '\n')
	{
		*line = ft_strsub(save[fd], 0, j);
		tmp = ft_strdup(save[fd] + j + 1);
		free(save[fd]);
		save[fd] = tmp;
		if (save[fd][0] == '\0')
			ft_strdel(&save[fd]);
	}
	else if (save[fd][j] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(save[fd]);
		ft_strdel(&save[fd]);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char *save[255];
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strnew(1);
		tmp = ft_strjoin(save[fd], buf);
		free(save[fd]);
		save[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && save[fd] == NULL)
		return (0);
	return (get_line(save, line, fd, ret));
}
