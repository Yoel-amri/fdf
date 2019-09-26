/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 02:54:31 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/19 01:41:44 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*b;

	if (!s)
		return (0);
	i = 0;
	j = ft_strlen(s);
	b = (char*)s;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t' || s[j] == '\0')
		j--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strdup(s + i));
	b = ft_strsub(s, i, (j - i + 1));
	if (b == NULL)
		return (NULL);
	return (b);
}
