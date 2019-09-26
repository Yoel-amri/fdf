/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:02:05 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/22 07:56:31 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	stock[n];

	if (n > 65535)
		return (NULL);
	ft_memcpy(stock, str2, n);
	ft_memcpy(str1, stock, n);
	return (str1);
}
