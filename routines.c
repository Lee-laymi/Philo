/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrsirab <skrsirab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:53:40 by skrsirab          #+#    #+#             */
/*   Updated: 2023/01/24 01:29:37 by skrsirab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void* routines(void *phi)
{
    t_philo *philoso;

    philoso = (t_philo *)phi;

    ft_forkeat(philoso);
    ft_sleep(philoso);

/* ft_forkeat() */
/* ft_sleepthink() */
/* ft_timpstamp() */
/* ft_print() */
/* ft_hold_eat() */

}

void    ft_forkeat(t_philo  *philoso)
{

    pthread_mutex_lock(&philoso->philo_data->q_fork[philoso->fork_left]);
    pthread_mutex_lock(&philoso->philo_data->q_fork[philoso->fork_right]);
/* print va philo has taken fork + time stamp */
    print_time(philoso, "is eating\n", CYAN);
/* update num of eat */

}

void    ft_sleep(t_philo   *philoso)
{
    ft_print(philoso, "is sleeping\n", GREENBG);
    ft_print(philoso, "is thinking\n", BLUEBG);
}

void    ft_print(t_philo *philoso, char *str, char *color)
{
    printf("%s%zu ms %d %s\n",color,philoso->timestamp,philoso->id,str);
}