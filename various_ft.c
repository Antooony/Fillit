/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:03:35 by adenis            #+#    #+#             */
/*   Updated: 2016/11/28 15:36:23 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstadd_end(t_list *alst, t_list *new)
{
	if (alst && new && alst->next)
		ft_lstadd_end(alst->next, new);
	else
		alst->next = new;
}

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

int		ft_check(char *s)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != '\n' && *s != '.' && *s != '#')
			return (0);
		if (*s == '#')
			i++;
		s++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int		ft_len(char **tab)
{
	int		i;

	i = 0;
	while (*tab)
	{
		tab++;
		i++;
	}
	return (i);
}
