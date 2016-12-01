/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:37:54 by adenis            #+#    #+#             */
/*   Updated: 2016/12/01 19:06:27 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkneg(int *tab)
{
	int		i;

	i = 0;
	if (tab[5] == -2)
		return (-2);
	while (i < 6)
	{
		if (tab[i] == -1)
			return (-1);
		i++;
	}
	return (0);
}

char	**ft_creategrid(int i)
{
	char	**tab;
	int		j;
	int		k;
	int		line;

	j = 0;
	k = 0;
	line = -1;
	tab = (char **)malloc(sizeof(char *) * i + 1);
	while (line++ < i)
		tab[line] = ft_strnew(i);
	tab[i] = NULL;
	while (j < i)
	{
		k = 0;
		while (k < i)
		{
			if (tab[j][k] != '.')
				tab[j][k] = '.';
			k++;
		}
		j++;
	}
	return (tab);
}

char	**fillgrid(t_list **lst, int x, int y, char **tab)
{
	int		*fig;
	int		k;
	t_list	*bli;

	k = 0;
	bli = *lst;
	fig = (int *)bli->content;
	y -= ft_checkneg(fig);
	tab[y][x] = bli->letter;
	tab[y + fig[1]][x + fig[0]] = bli->letter;
	tab[y + fig[3]][x + fig[2]] = bli->letter;
	tab[y + fig[5]][x + fig[4]] = bli->letter;
	bli->used = 1;
	*lst = bli;
	return (tab);
}

int		testfig(t_list *lst, int x, int y, char **tab)
{
	int		*fig;
	int		k;
	int		len;

	k = 0;
	len = ft_tablen(tab);
	fig = (int *)lst->content;
	y -= ft_checkneg(fig);
	if (y < len && (y + fig[1] < len) && (y + fig[3] < len) && (y + fig[5] < len))
	{
		if (tab[y + fig[1]][x + fig[0]] == '.' &&
				tab[y + fig[3]][x + fig[2]] == '.' &&
					tab[y + fig[5]][x + fig[4]] == '.' &&
						tab[y][x] == '.')
			return (1);
	}
	return (0);
}
