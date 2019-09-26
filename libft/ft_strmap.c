/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 23:08:05 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/19 01:32:02 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*b;

	i = 0;
	if (!s || !f)
		return (0);
	b = (char*)malloc(sizeof(*b) * (ft_strlen(s) + 1));
	if (b == NULL)
		return (NULL);
	if (s != NULL && f != NULL)
	{
		while (s[i] != '\0')
		{
			b[i] = f(s[i]);
			i++;
		}
		b[i] = '\0';
		return (b);
	}
	else
		return (NULL);
}
