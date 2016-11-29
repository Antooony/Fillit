/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:05:25 by adenis            #+#    #+#             */
/*   Updated: 2016/11/29 11:15:19 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
