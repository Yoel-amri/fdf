/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 20:19:53 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/19 01:39:33 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*b;
	size_t	i;

	i = 0;
	b = (char*)malloc(sizeof(*b) * (size + 1));
	if (b == NULL)
		return (NULL);
	while (i <= size)
	{
		b[i] = '\0';
		i++;
	}
	return (b);
}
