/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:21:17 by adenis            #+#    #+#             */
/*   Updated: 2016/12/02 18:06:47 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_removefig(t_list **lst, char **tab)
{
	int		i;
	int		j;
	t_list	*bli;

	bli = *lst;
	bli->used = 0;
	*lst = bli;
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == bli->letter)
				tab[j][i] = '.';
			i++;
		}
		j++;
	}
	return (tab);
}

t_list	*ft_cleanlst(t_list *lst)
{
	while (lst->next)
	{
		lst->used = 0;
		lst = lst->next;
	}
	return (ft_go_back(lst));
}

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

int		ft_check_and_fill(t_list *lst, char ***tab, int len)
{
	int		x;
	int		y;
	int		test;

	test = 0;
	x = -1;
	y = -1;
	if (!lst)
		return (0);
	while (++y < len && lst)
	{
		x = -1;
		while (++x < len && lst)
		{
			if ((test = testfig(lst, x, y, *tab)))
			{
				*tab = fillgrid(&lst, x, y, *tab);
				if (!lst->next || ft_check_and_fill(ft_go_back(lst), tab, len))
					return (1);
				else
					*tab = ft_removefig(&lst, *tab);
			}
		}
	}
	return (0);
}

void	ft_solve_it(t_list *lst, int len)
{
	char	**tab;

	tab = ft_creategrid(len);
	if (ft_check_and_fill(lst, &tab, len))
		ft_return(tab);
	else
		ft_solve_it(ft_cleanlst(lst), len + 1);
}
