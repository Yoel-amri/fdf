/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 02:32:57 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/18 23:34:55 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*b;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	if (!(b = (char*)malloc(sizeof(b) * (ft_strlen(s1) + ft_strlen(s2)))))
		return (0);
	while (s1[i] != '\0')
	{
		b[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		b[i] = s2[j];
		i++;
		j++;
	}
	b[i] = '\0';
	return (b);
}
