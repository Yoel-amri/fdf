/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:07:31 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/13 16:49:27 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*h;

	i = 0;
	h = (char *)haystack;
	if (needle[0] == '\0')
		return (h);
	while (h[i] != '\0')
	{
		j = 0;
		while (h[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return (h + i);
			j++;
		}
		i++;
	}
	return (0);
}
