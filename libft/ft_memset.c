/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 01:11:47 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/21 08:31:34 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	ch;
	char			*p;

	i = 0;
	ch = c;
	p = (char*)str;
	while (i < len)
	{
		p[i] = ch;
		i++;
	}
	return (str);
}
