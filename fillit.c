/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:23:24 by adenis            #+#    #+#             */
/*   Updated: 2016/11/27 16:26:45 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_in(char *str)
{
	int		i;
	int		start;
	int		count;

	i = 1;
	start = -1;
	count = 0;
	while (str[i + start])
	{
		if (count == 4)
		{
			start++;
			count = 0;
		}
		if (!(i % 5) && str[i + start] == '\n')
			count++;
		if (!(i % 5) && str[i + start] != '\n')
			break ;
		if (count != 4 && str[i + start] == '\n' && str[i + start + 1] == '\n')
			break ;
		i++;
	}
	if (!str[i + start] && count == 4)
		return (1);
	return (0);
}

t_list	*get_lst(char **tab)
{
	int		i;
	t_list	*ret;
	t_list	*new;
	char	*str;

	i = 0;
	str = NULL;
	ret = ft_lstnew(NULL, 0);
	while (*tab)
	{
		if (i == 4)
		{
			new = ft_lstnew(ft_strdup(str), ft_strlen(str) + 1);
			ft_lstadd_end(ret, new);
			i = 0;
			str = NULL;
		}
		str = get_str(str, *tab);
		tab++;
		i++;
	}
	new = ft_lstnew(ft_strdup(str), ft_strlen(str) + 1);
	ft_lstadd_end(ret, new);
	ret = ret->next;
	return (ret);
}

void	fillit(char *str)
{
	t_list	*lst;

	if(check_in(str) && ft_checkc(str) && ft_len(ft_strsplit(str, '\n')) <= 104)
	{
		lst = get_lst(ft_strsplit(str, '\n'));
	}
	else
	{
		lst = NULL;
		ft_putstr("invalid map");
	}
	if (lst)
	{
		while (lst)
		{
			ft_putendl(lst->content);
			lst = lst->next;
		}
	}
}
