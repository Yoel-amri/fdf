/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:47:29 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/13 16:46:18 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	b;

	p = (unsigned char*)str;
	b = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == b)
			return (p + i);
		i++;
	}
	return (NULL);
}
