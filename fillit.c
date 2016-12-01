/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:23:24 by adenis            #+#    #+#             */
/*   Updated: 2016/12/01 18:36:39 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_return(char **tab)
{
	while (*tab)
	{
		ft_putendl(*tab);
		tab++;
	}
}

void	lst_display(t_list *lst)
{
	while (lst)
	{
		ft_putnbr_tab(lst->content);
		ft_putchar('\n');
		lst = lst->next;
	}
}

int		ft_sqrtt(int nb)
{
	int		result;

	result = 0;
	if (nb < 0)
		return (0);
	while ((result * result) < nb)
		result++;
	return (result);
}

void	fillit(char *str)
{
	t_list	*lst;
	int		len;

	len = ft_tablen(ft_strsplit(str, '\n'));
	if (check_in(str) && ft_check(str) && len <= 104)
	{
		lst = get_lst(ft_strsplit(str, '\n'));
		ft_lstiter(lst, &lstsub);
		ft_lstiter(lst, &ft_check_tetri);
		ft_lstiter(lst, &ft_getox);
	}
	else
	{
		ft_putendl("error");
		exit(1);
	}
	ft_solve_it(lst, 4);
}
