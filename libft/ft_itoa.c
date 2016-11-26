/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:04:50 by adenis            #+#    #+#             */
/*   Updated: 2016/11/14 12:51:13 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_len(int *n, int *min)
{
	int		i;
	int		len;

	len = 1;
	i = 1;
	if (*n < 0)
	{
		*min = *min + 1;
		*n *= -1;
		len++;
	}
	while ((*n / i) >= 10)
	{
		i *= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		len;
	int		min;
	char	*str;

	min = 0;
	if (n == -2147483648)
	{
		str = ft_strnew(12);
		ft_strcpy(str, "-2147483648");
		str[11] = '\0';
		return (str);
	}
	len = ft_get_len(&n, &min);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (min == 1)
		str[0] = '-';
	while (len-- > min)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
