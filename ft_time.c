/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:58:02 by skrairab          #+#    #+#             */
/*   Updated: 2023/05/07 00:14:31 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_getcurrenttime(void)
{
	struct timeval	currenttime;

	gettimeofday(&currenttime, NULL);
	return ((currenttime.tv_sec * 1000) + (currenttime.tv_usec / 1000));
}

int	ft_usleep_gettime(int timestamp, t_philo *p)
{
	long	get_timestamp;

	get_timestamp = ft_getcurrenttime();
	while (ft_getcurrenttime() - get_timestamp < (long) timestamp)
	{
		if (p->env->sign == 1)
			return (1);
		usleep(700);
	}
	return (0);
}

long	ft_gettime(t_philo *philo)
{
	long	t;

	t = ft_getcurrenttime();
	return (t - (philo->env->timestamp));
}
