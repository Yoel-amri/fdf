/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:10:23 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/19 01:41:30 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	negative(int *nb, int *signe)
{
	if (*nb < 0)
	{
		*nb *= -1;
		*signe = 1;
	}
}

char			*ft_itoa(int nb)
{
	char	*str;
	int		tmp;
	int		signe;
	int		len;

	len = 2;
	tmp = nb;
	signe = 0;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	negative(&nb, &signe);
	while (tmp /= 10)
		len++;
	len += signe;
	if ((str = (char*)malloc(sizeof(char) * (len))) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (signe)
		str[0] = '-';
	return (str);
}
