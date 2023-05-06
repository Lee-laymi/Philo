/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:38:05 by skrairab          #+#    #+#             */
/*   Updated: 2023/05/07 00:39:21 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_time(t_philo *p)
{
	long	time_now;
	int		i;

	i = 1;
	while (i <= p->env->n_philo)
	{
		time_now = ft_getcurrenttime();
		if (time_now - p->cur_t2eat >= (long)p->t2die
			&& (p->n2eat_check < p->n2eat))
		{
			ft_print(ft_gettime(p), "DIE", REDBG, p);
			p->env->sign = 1;
			return (1);
		}
		i++;
		p = p->next;
	}
	return (0);
}

void	*ft_checkdie(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		if (ft_check_time(p) == 1 || (philo->n2eat_check >= philo->n2eat))
			break ;
	}
	while (philo->env->unlock_fork)
		ft_unlock_fork(philo);
	return (NULL);
}
