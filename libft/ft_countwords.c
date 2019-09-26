/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:12:26 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/22 10:16:01 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char const *s, char c)
{
	int state;
	int	j;

	if (!s)
		return (0);
	j = 0;
	state = 1;
	while (*s != '\0')
	{
		if (*s == c)
			state = 1;
		else if (state == 1)
		{
			state = 0;
			j++;
		}
		s++;
	}
	return (j);
}
