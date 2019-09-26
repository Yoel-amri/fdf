/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:20:57 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/13 16:48:24 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;
	char	*s1;

	i = 0;
	len = ft_strlen(s);
	s1 = (char*)s;
	while (i < len)
	{
		if (s1[len] == c)
			return (s1 + len);
		i++;
		len--;
	}
	len = ft_strlen(s);
	if (s1[len / 2] == c)
		return (s1 + (len / 2));
	if (s1[0] == c)
		return (s1);
	return (NULL);
}
