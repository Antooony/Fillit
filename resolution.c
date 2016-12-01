/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:21:17 by adenis            #+#    #+#             */
/*   Updated: 2016/12/01 19:24:48 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fullused(t_list *lst)
{
	while (lst)
	{
		if (lst->used)
			lst = lst->next;
		else
			break ;
	}
	if (!lst)
		return (1);
	return (0);
}

char	**ft_check_and_fill(t_list *lst, char **tab, int len)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < len && lst)
	{
		x = 0;
		while (x < len && lst)
		{
			if (testfig(lst, x, y, tab))
			{
				tab = fillgrid(&lst, x, y, tab);
				lst = lst->next;
				y = 0;
			}
			x++;
		}
		y++;
	}
	return (tab);
}

void	ft_solve_it(t_list *lst, int len)
{
	char 	**tab;

	tab = ft_creategrid(len);
	tab = ft_check_and_fill(lst, tab, len);
	if (ft_fullused(lst))
		ft_return(tab);
	else
		ft_solve_it(lst, len + 1);
}
