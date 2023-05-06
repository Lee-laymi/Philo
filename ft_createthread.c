/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createthread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 03:46:28 by skrairab          #+#    #+#             */
/*   Updated: 2023/05/07 01:42:16 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	ft_createthread(t_env *philoenv)
// {
// 	int		i;
// 	t_philo	*tmp_thread;
// 	t_philo	*tmp_check;

// 	i = 0;
// 	tmp_thread = philoenv->philo;
// 	philoenv->timestamp = ft_getcurrenttime();
// 	if (ft_create_odd(tmp_thread) != 0)
// 		return (1);
// 	usleep(50);
// 	tmp_thread = philoenv->philo;
// 	if (ft_create_even(tmp_thread) != 0)
// 		return (1);
// 	tmp_check = philoenv->philo;
// 	if (pthread_create(& (philoenv->checker), NULL, &ft_checkdie, tmp_check) != 0)
// 		return (1);
// 	tmp_thread = philoenv->philo;
// 	while (i < philoenv->n_philo)
// 	{
// 		if (pthread_join (tmp_thread->thread, NULL) != 0)
// 			return (1);
// 		tmp_thread = tmp_thread->next;
// 		i++;
// 	}
// 	philoenv->unlock_fork = 0;
// 	if (pthread_join (philoenv->checker, NULL) != 0)
// 		return (1);
// 	return (0);
// }

int	create_mutex(t_env *philoenv)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	tmp = philoenv->philo;
	while (i < philoenv->n_philo)
	{
		if (pthread_mutex_init(&tmp->mutex_fork, NULL) != 0)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	ft_pthread_mutex_destroy(t_env *philoenv)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = philoenv->philo;
	while (i < p->env->n_philo)
	{
		pthread_mutex_destroy(&p->mutex_fork);
		p = p->next;
		i++;
	}
}

void	ft_unlock_fork(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->env->n_philo)
	{
		pthread_mutex_unlock(&p->mutex_fork);
		pthread_mutex_unlock(&p->next->mutex_fork);
		p = p->next;
		i = i + 1;
	}
}

int	ft_createthread(t_env *philoenv)
{
	int		i;
	t_philo	*tmp_thread;
	t_philo	*tmp_check;

	i = 0;
	tmp_thread = philoenv->philo;
	philoenv->timestamp = ft_getcurrenttime();
	if (ft_create_odd(tmp_thread) != 0)
		return (1);
	usleep(50);
	tmp_thread = philoenv->philo;
	if (ft_create_even(tmp_thread) != 0)
		return (1);
	tmp_check = philoenv->philo;
	if (pthread_create(& (philoenv->checker), NULL, &ft_checkdie, tmp_check) != 0)
		return (1);
	tmp_thread = philoenv->philo;
	ft_pthreadjoin(philoenv);
	philoenv->unlock_fork = 0;
	if (pthread_join (philoenv->checker, NULL) != 0)
		return (1);
	return (0);
}


int		ft_pthreadjoin(t_env *philoenv)
{
	int		i;
	t_philo	*tmp_thread;

	i = 0;
	tmp_thread = philoenv->philo;
	while (i < philoenv->n_philo)
	{
		if (pthread_join (tmp_thread->thread, NULL) != 0)
			return (1);
		tmp_thread = tmp_thread->next;
		i++;
	}
	return (0);
}
