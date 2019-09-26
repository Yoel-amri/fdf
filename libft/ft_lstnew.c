/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 03:38:15 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/20 01:01:43 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list *tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp != NULL)
	{
		if (content == NULL)
		{
			tmp->content = NULL;
			tmp->content_size = 0;
			tmp->next = NULL;
		}
		else
		{
			if (!(tmp->content = malloc(content_size)))
				return (NULL);
			ft_memcpy(tmp->content, content, content_size);
			tmp->content_size = content_size;
			tmp->next = NULL;
		}
		return (tmp);
	}
	return (NULL);
}
