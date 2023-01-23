/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrsirab <skrsirab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:35:38 by ami               #+#    #+#             */
/*   Updated: 2023/01/23 23:45:59 by skrsirab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (destsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < (destsize - 1) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	if (i < destsize)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	value;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	value = 0;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		value *= 10;
		value += str[i++] - '0';
	}
	value *= sign;
	if (value < -2147483648 || value > 2147483647)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
		//ft_atoi_error(num, par);
	return ((int)value);
}
