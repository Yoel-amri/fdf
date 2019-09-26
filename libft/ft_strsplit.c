/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 04:54:39 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/20 15:34:16 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count(char const *s, char c)
{
	int state;
	int j;

	if (!s)
		return (0);
	j = 0;
	state = 1;
	while (*s != '\0')
	{
		if (*s == c)
			state = 1;
		else if (state == 1)
		{
			state = 0;
			j++;
		}
		s++;
	}
	return (j);
}

static	int	ft_len(char const *s, char c)
{
	int j;

	if (!s)
		return (0);
	j = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		j++;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		index;
	char	**tab;
	int		nb;

	i = 0;
	index = 0;
	nb = ft_count((char const *)s, c);
	if (!s)
		return (NULL);
	if ((tab = (char**)malloc(sizeof(char*) * nb + 1)) == NULL)
		return (NULL);
	while (nb--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[index] = ft_strsub(s, 0, ft_len((char const *)s, c));
		if (tab[index] == NULL)
			return (NULL);
		index++;
		s = s + ft_len(s, c);
	}
	tab[index] = NULL;
	return (tab);
}
