/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:53:40 by skrsirab          #+#    #+#             */
/*   Updated: 2023/05/07 01:38:58 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routines(void *phi)
{
	t_philo	*p;

	p = phi;
	p->cur_t2eat = ft_getcurrenttime();
	while (1)
	{
		if (ft_forkeat(p) == 1)
			break ;
		if (p->n2eat_check == p->n2eat)
			break ;
		if (ft_sleep(p) == 1)
			break ;
	}
	return (0);
}

int	ft_forkeat(t_philo *p)
{
	if (p->env->sign == 1)
		return (1);
	pthread_mutex_lock(&p->next->mutex_fork);
	if (p->env->sign == 1)
		return (1);
	pthread_mutex_lock(&p->mutex_fork);
	if (p->env->sign == 1)
		return (1);
	ft_print(ft_gettime(p), "Fork right", GREEN, p);
	ft_print(ft_gettime(p), "Fork left", BLUE, p);
	ft_print(ft_gettime(p), "is eating", CYAN, p);
	if (ft_usleep_gettime(p->t2eat, p) == 1)
		return (1);
	p->n2eat_check = p->n2eat_check + 1;
	p->cur_t2eat = ft_getcurrenttime();
	pthread_mutex_unlock(&p->next->mutex_fork);
	if (p->env->sign == 1)
		return (1);
	pthread_mutex_unlock(&p->mutex_fork);
	if (p->env->sign == 1)
		return (1);
	return (0);
}

int	ft_sleep(t_philo *p)
{
	if (p->env->sign == 1)
		return (1);
	ft_print(ft_gettime(p), "is sleeping", WHITE, p);
	if (ft_usleep_gettime(p->t2sleep, p) == 1)
		return (1);
	if (p->env->sign == 1)
		return (1);
	ft_print(ft_gettime(p), "is thinking", MAGENTA, p);
	return (0);
}

void	ft_print(long gettime, char *str, char *color, t_philo *p)
{
	printf("%s%ld ms %d %s\n", color, gettime, p->id, str);
}
