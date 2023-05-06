/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:47:12 by skrairab          #+#    #+#             */
/*   Updated: 2023/05/07 03:06:16 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_odd(t_philo *tmp_thread)
{
	int		i;
	t_philo	*tmp1;

	i = 1;
	tmp1 = tmp_thread;
	while (i <= tmp_thread->env->n_philo)
	{
		if (pthread_create(&(tmp1->thread), NULL, &routines, tmp1) != 0)
			return (1);
		usleep(5);
		tmp1 = tmp1->next->next;
		i = i + 2;
	}
	return (0);
}

int	ft_create_even(t_philo *tmp_thread)
{
	int		i;
	t_philo	*tmp2;

	i = 2;
	tmp2 = tmp_thread->next;
	while (i <= tmp_thread->env->n_philo)
	{
		if (pthread_create(&(tmp2->thread), NULL, &routines, tmp2) != 0)
			return (1);
		usleep(5);
		tmp2 = tmp2->next->next;
		i = i + 2;
	}
	return (0);
}

void	ft_addphilo(t_philo *p, char **av, t_env *philoenv, int i)
{
	if (av[5])
	{
		p->n2eat = ft_atoi(av[5]);
		p->n2eat_check = 0;
	}
	else
		p->n2eat = 0;
	p->t2die = ft_atoi(av[2]);
	p->t2eat = ft_atoi(av[3]);
	p->t2sleep = ft_atoi(av[4]);
	p->env = philoenv;
	p->next = NULL;
	if (i < p->env->n_philo)
	{
		p->next = malloc(sizeof(t_philo));
		if (!p->next)
			return ;
	}
}

int	create_philo(char **av, t_env *philoenv)
{
	int		i;
	t_philo	*tmp_philo;
	t_philo	*tmp_head;

	i = 1;
	philoenv->philo = malloc(sizeof(t_philo));
	if (!philoenv->philo)
		return (1);
	tmp_philo = philoenv->philo;
	tmp_head = philoenv->philo;
	philoenv->n_philo = ft_atoi(av[1]);
	while (i <= philoenv->n_philo)
	{
		tmp_philo->id = i;
		ft_addphilo(tmp_philo, av, philoenv, i);
		tmp_philo = tmp_philo->next;
		i++;
	}
	tmp_philo = tmp_head;
	while (tmp_philo->next != NULL)
		tmp_philo = tmp_philo->next;
	tmp_philo->next = tmp_head;
	return (0);
}
