/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:28:55 by adenis            #+#    #+#             */
/*   Updated: 2016/11/28 16:37:47 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static const char	*Table[] =
{
	"#..###",
	"#...##..#",
	"###..#",
	"#..##...#",
	"####",
	"#...#...#...#",
	"#...#...##",
	"#.###",
	"##...#...#",
	"###.#",
	"#...###",
	"#...#..##",
	"###...#",
	"##..#...#",
	"##..##",
	"##.##",
	"##...##",
	"#..##..#",
	"#...##...#"
};

void			ft_rename(t_list *lst)
{
	static int	c = 'A';
	char		*tmp;
	int			i;

	i = 0;
	tmp = ft_strdup(lst->content);
	while (tmp[i])
	{
		if (tmp[i] == '#')
			tmp[i] = c;
		i++;
	}
	lst->content = tmp;
	c += 1;
}

void			ft_check_tetri(t_list *lst)
{
	int			i;

	i = 0;
	while (Table[i])
	{
		if (!ft_strcmp(Table[i], lst->content))
			break ;
		i++;
	}
	if (i > 18)
	{
		ft_putstr_fd("error", 2);
		exit(1);
	}
}
