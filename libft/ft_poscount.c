/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poscount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 08:34:31 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/22 10:10:30 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_poscount(char const *s, char c)
{
	int	*ptab;
	int i;
	int j;

	i = 0;
	j = 1;
	ptab = (int*)malloc(sizeof(int) * ft_countwords(s, c));
	ptab[0] = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
		{
			ptab[j] = i + 1;
			j++;
		}
		i++;
	}
	return (ptab);
}
