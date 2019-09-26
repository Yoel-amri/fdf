/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:01:13 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/20 11:09:07 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const	unsigned char	*s1;
	const	unsigned char	*s2;

	s1 = (const	unsigned char*)str1;
	s2 = (const	unsigned char*)str2;
	if (str1 == str2 || n == 0)
		return (0);
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (n)
		{
			s1++;
			s2++;
		}
	}
	return (0);
}
