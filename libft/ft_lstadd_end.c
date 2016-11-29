/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:03:13 by adenis            #+#    #+#             */
/*   Updated: 2016/11/29 11:04:06 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list *alst, t_list *new)
{
	if (alst && new && alst->next)
		ft_lstadd_end(alst->next, new);
	else
		alst->next = new;
}
