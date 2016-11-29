/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:23:24 by adenis            #+#    #+#             */
/*   Updated: 2016/11/29 11:21:11 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(char *str)
{
	t_list	*lst;

	if (check_in(str) && ft_check(str) && \
		ft_tablen(ft_strsplit(str, '\n')) <= 104)
	{
		lst = get_lst(ft_strsplit(str, '\n'));
		ft_lstiter(lst, &lstsub);
		ft_lstiter(lst, &ft_check_tetri);
		ft_lstiter(lst, &ft_getox);
	}
	else
		lst = NULL;
	if (!lst)
		ft_putstr_fd("error", 2);
	else
	{
		ft_putendl("carte valide");
		while (lst)
		{
			ft_putnbr_tab(lst->content);
			ft_putchar(' ');
			ft_putchar(lst->letter);
			ft_putchar('\n');
			lst = lst->next;
		}
	}
}
