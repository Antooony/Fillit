/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:23:24 by adenis            #+#    #+#             */
/*   Updated: 2016/11/29 13:20:24 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	lst_display(t_list *lst)
{
	while(lst)
	{
		ft_putendl(lst->content);
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
	{
		ft_putstr_fd("error", 2);
		exit(1);
	}
	else
	{
		printparams(lst);
		// printtetri(lst, ft_sqrtt(ft_tablen(ft_strsplit(str, '\n'))));
	}
}

void	printparams(t_list *lst)
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

// void	printtetri(t_list *lst, int	i)
// {
// 	char		**grid;

// 	ft_putnbr_tab(lst->content);

// 	grid = ft_newgrid(i);
// 	while (grid)
// 	{
// 		ft_putendl(*grid);
// 		grid++;
// 	}
	
// }