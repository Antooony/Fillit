/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:53:12 by adenis            #+#    #+#             */
/*   Updated: 2016/11/29 10:50:36 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int		result;

	result = 0;
	if (nb < 0)
		return (0);
	while ((result * result) < nb)
		result++;
	if ((result * result) != nb)
		return (0);
	else
		return (result);
}
