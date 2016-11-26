/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:11:32 by adenis            #+#    #+#             */
/*   Updated: 2016/11/26 13:13:40 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_create_str(char **argv)
{
	char	buffer[575];
	char	*str;
	int		ret;
	int		fd;

	ret = 0;
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd != -1)
	{
		ret = read(fd, buffer, 575);
		if (ret != -1 && ret <= 575)
		{
			buffer[ret] = '\0';
			str = ft_strnew(ret);
			str = ft_strcpy(str, buffer);
			return (str);
		}
	}
	ft_putendl("Error\n");
	return (NULL);
}

int		main(int argc, char **argv)
{
	char	*str;

	if (argc == 2)
	{
		str = ft_create_str(argv);
		if (str != NULL)
		{
			fillit(str);
		}
	}
	return (0);
}
