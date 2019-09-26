/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 23:32:30 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/18 23:36:44 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*b;

	i = 0;
	if (!s || !f)
		return (0);
	b = (char*)malloc(sizeof(*b) * (ft_strlen(s) + 1));
	if (b == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		b[i] = f(i, s[i]);
		i++;
	}
	b[i] = '\0';
	return (b);
}
