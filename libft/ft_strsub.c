/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 01:59:48 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/20 15:28:21 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*b;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	b = (char*)malloc(sizeof(*b) * (len + 1));
	if (b == NULL)
		return (NULL);
	while (i < len)
	{
		b[i] = s[start];
		start++;
		i++;
	}
	b[i] = '\0';
	return (b);
}
