/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:53:40 by skrsirab          #+#    #+#             */
/*   Updated: 2023/04/11 12:46:35 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routines(void *phi)
{
    // t_env *p;

    // p = (t_env *)phi;
    t_philo *p;

    p = phi;
    if (ft_forkeat(p) != 0)
        return (0);
    // ft_sleep(p);
    /*ft_sleep();*/
    /* ft_timpstamp() */
    // ft_print(ft_gettime(p->philo), "is die", BLUEBG, p);
    /* ft_hold_eat() */
return (0);

}

int    ft_forkeat(t_philo  *p)
{
   // if (ft_gettime)
    pthread_mutex_lock(&p->next->mutex_fork);
    ft_print(ft_gettime(p),"Fork right" , GREENBG, p->env);
    pthread_mutex_lock(&p->mutex_fork);
    ft_print(ft_gettime(p),"Fork left" , BLUEBG, p->env);
    ft_print(ft_gettime(p),  "is eating\n", CYAN, p->env);
    pthread_mutex_unlock(&p->next->mutex_fork);
    pthread_mutex_unlock(&p->mutex_fork);
/* print va philo has taken fork + time stamp */
/* update num of eat */
    return (0);
}

void    ft_sleep(t_philo   *p)
{
    ft_print(ft_gettime(p), "is sleeping\n", GREENBG, p->env);
    ft_print(ft_gettime(p), "is thinking\n", BLUEBG, p->env);
}

void    ft_print(long gettime, char *str, char *color, t_env *p)
{
    printf("%s%ld ms %d %s\n",color,gettime,p->philo->id,str);
}