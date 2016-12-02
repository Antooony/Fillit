/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:03:35 by adenis            #+#    #+#             */
/*   Updated: 2016/12/02 18:34:25 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_get_ret(char *dest, char *src)
{
	char	*tmp;

	tmp = ft_strdup(dest);
	dest = ft_strnew(ft_strlen(tmp) + ft_strlen(src));
	dest = ft_strjoin(tmp, src);
	free(tmp);
	return (dest);
}

char	*get_str(char *str, char *tab)
{
	if (str)
		str = ft_get_ret(str, tab);
	if (!str)
		str = ft_strdup(tab);
	return (str);
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
		ft_putendl("error");
		exit(0);
	}
	tmp = ft_strsub(lst->content, start, (end - start) + 1);
	free(lst->content);
	lst->content = tmp;
	lst->content_size = ft_strlen(tmp);
}

t_list	*get_lst(char **tab)
{
	int		i;
	t_list	*ret;
	t_list	*new;
	char	*str;

	i = -1;
	str = NULL;
	ret = ft_lstnew(NULL, 0);
	while (*tab)
	{
		if (++i == 4)
		{
			new = ft_lstnew(ft_strdup(str), ft_strlen(str) + 1);
			ft_lstadd_end(ret, new);
			i = 0;
			str = NULL;
		}
		str = get_str(str, *tab);
		tab++;
	}
	new = ft_lstnew(ft_strdup(str), ft_strlen(str) + 1);
	ft_lstadd_end(ret, new);
	new->prev = ret;
	ret = ret->next;
	return (ret);
}

void	ft_cpytab(int *dst, int *tab)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		dst[i] = tab[i];
		i++;
	}
}
