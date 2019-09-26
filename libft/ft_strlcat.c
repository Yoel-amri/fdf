/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:26:45 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/22 08:09:01 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstl;
	size_t	srcl;

	srcl = ft_strlen(src);
	dstl = ft_strlen(dst);
	i = 0;
	j = 0;
	if (size <= dstl)
		return (srcl + size);
	while (dst[i] != '\0' && i < (size - 1))
		i++;
	while (src[j] != '\0' && i < (size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dstl + srcl);
}
