/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:23:24 by adenis            #+#    #+#             */
/*   Updated: 2016/11/30 12:08:30 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkneg(int	*tab)
{
	int		i;

	i = 0;
	if (tab[5] == -2)
		return (-2);
	while (i < 6)
	{
		if(tab[i] == -1)
			return (-1);
		i++;
	}
	return (0);
}

char	**ft_creategrid(int	i)
{
	char	**tab;
	int		j;
	int		k;
	int		line;

	j = 0;
	k = 0;
	line = 0;
	tab = (char **)malloc(sizeof(char *) * i + 1);
	while (line < i)
	{
		tab[line] = ft_strnew(i);
		line++;
	}
	tab[i] = NULL;

	while (j < i)
	{
		k = 0;
		while(k < i)
		{
			tab[j][k] = '.';
			k++;
		}
		j++;
	}
	return (tab);
}

char	**fillgrid(t_list *lst, int	x, int	y, char **tab)
{
	int		*fig;
	int		k;

	k = 0;
	fig = (int *)lst->content;
	y -= ft_checkneg(fig);
		tab[y][x] = lst->letter;
		tab[y + fig[1]][x + fig[0]] = lst->letter;
		tab[y + fig[3]][x + fig[2]] = lst->letter;
		tab[y + fig[5]][x + fig[4]] = lst->letter;
	return (tab);
}

int		testgrid(t_list *lst, int	x, int	y, char **tab)
{
	int		*fig;
	int		k;

	k = 0;
	fig = (int *)lst->content;
	y -= ft_checkneg(fig);
	if (tab[y + fig[1]][x + fig[0]] == '.' && tab[y + fig[1]][x + fig[0]] &&
			tab[y + fig[3]][x + fig[2]] == '.' && tab[y + fig[3]][x + fig[2]] &&
				tab[y + fig[5]][x + fig[4]] == '.' && tab[y + fig[5]][x + fig[4]] &&
					tab[y][x] == '.' && tab[y][x])
		return (1);
	return (0);
}

char	**ft_check_and_fill(t_list *lst, char **tab)
{
	int		x;
	int		y;
	int		max;

	x = 0;
	y = 0;
	max = ft_strlen(tab[0]);
	while (y < max - 2)
	{
		x = 0;
		while (x < max - 2)
		{
			if (testgrid(lst, x, y, tab))
			{
				tab = fillgrid(lst, x, y, tab);
				if (lst->next)
					lst = lst->next;
				else
					break;
			}
			x++;
		}
		if (!lst->next)
			break;
		y++;
	}
	return (tab);
}

void	lst_display(t_list *lst)
{
	while (lst)
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
	char	**tab;
	int		i;
	
	i = 0;
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
		tab = ft_creategrid(12);
		// tab = fillgrid(lst, 0, 0, tab);
		tab = ft_check_and_fill(lst, tab);

			while (tab[i])
			{
				ft_putendl(tab[i]);
				i++;
			}
			ft_putchar('\n');
		
	}
		// printparams(lst);
}

void	printparams(t_list *lst)
{
	while (lst)
	{
		ft_putnbr_tab(lst->content);
		ft_putchar(' ');
		ft_putchar(lst->letter);
		ft_putchar('\n');
		lst = lst->next;
	}
}
