/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:23:24 by adenis            #+#    #+#             */
/*   Updated: 2016/11/29 10:58:37 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_str(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == '#')
			i++;
		str++;
	}
	if (i == 4)
		return (1);
	return (0);
}

void	lstsub(t_list *lst)
{
	int		end;
	int		start;
	char	*tmp;

	end = ft_strlen(lst->content);
	start = 0;
	tmp = ft_strdup(lst->content);
	while (tmp[start] != '#')
		start++;
	while (tmp[end] != '#')
		end--;
	if (!ft_check_str(lst->content))
	{
		ft_putstr_fd("error", 2);
		exit(0);
	}
	tmp = ft_strsub(lst->content, start, (end - start) + 1);
	free(lst->content);
	lst->content = tmp;
	lst->content_size = ft_strlen(tmp);
}

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

	if (check_in(str) && ft_check(str) && ft_tablen(ft_strsplit(str, '\n')) <= 104)
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
