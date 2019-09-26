/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:09:19 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/20 17:13:42 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*h;
	size_t	k;

	i = 0;
	k = ft_strlen(needle);
	h = (char *)haystack;
	if (needle[0] == '\0')
		return (h);
	while (*h != '\0' && len-- >= k)
	{
		if (*h == *needle && (ft_memcmp(h, needle, k) == 0))
			return ((char *)h);
		h++;
	}
	return (NULL);
}
