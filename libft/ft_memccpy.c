/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 07:57:09 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/17 22:21:13 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*s1;
	const unsigned char *s2;
	size_t				i;

	s1 = (unsigned char*)dest;
	s2 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		if (s2[i] == (unsigned char)c)
		{
			s1[i] = s2[i];
			i++;
			return (s1 + i);
		}
		s1[i] = s2[i];
		i++;
	}
	return (NULL);
}
