/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 06:36:01 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/21 10:59:31 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	const char	*s2;
	char		*s1;
	size_t		i;

	s1 = (char*)str1;
	s2 = (char*)str2;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (str1);
}
