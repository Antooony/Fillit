/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:39:50 by adenis            #+#    #+#             */
/*   Updated: 2016/12/02 14:59:23 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		if (!content)
		{
			new->content = NULL;
			new->content_size = 0;
			new->letter = 0;
			new->used = 0;
		}
		else
		{
			new->content = (void *)malloc(sizeof(content) * content_size);
			ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
		}
		new->next = NULL;
		new->prev = NULL;
		return (new);
	}
	return (NULL);
}
