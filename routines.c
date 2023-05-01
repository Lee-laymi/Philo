/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:53:40 by skrsirab          #+#    #+#             */
/*   Updated: 2023/05/01 16:21:53 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routines(void *phi)
{
    t_philo *p;

    p = phi;
   // if (ft_forkeat(p) != 0)
    p->cur_t2eat = ft_getCurrentTime();
    while ((ft_getCurrentTime() - (p->cur_t2eat)) < p->t2die)
    {
        // printf(" diff %ld\n", ((ft_getCurrentTime() - (p->cur_t2eat))));
        // printf("cur_t2eat %ld, curtime %ld\n", p->cur_t2eat,ft_getCurrentTime());
        // printf("philo id = %d\n", p->id);
        ft_forkeat(p);
        ft_sleep(p);
    }
    /*ft_sleep();*/
    /* ft_timpstamp() */
    // ft_print(ft_gettime(p->philo), "is die", BLUEBG, p);
    /* ft_hold_eat() */
return (0);
}

void    ft_forkeat(t_philo  *p)
{
    // if (p->env->n_philo > 1)
    // {
        pthread_mutex_lock(&p->next->mutex_fork);
        pthread_mutex_lock(&p->mutex_fork);
        ft_print(ft_gettime(p),"Fork right" , GREENBG, p);
        ft_print(ft_gettime(p),"Fork left" , BLUEBG, p);
        ft_print(ft_gettime(p),  "is eating", CYAN, p);
        ft_usleep_gettime(p->t2eat);
        p->cur_t2eat = ft_getCurrentTime();
        pthread_mutex_unlock(&p->next->mutex_fork);
        pthread_mutex_unlock(&p->mutex_fork);
    // }
/* print va philo has taken fork + time stamp */
/* update num of eat */
}

void    ft_sleep(t_philo   *p)
{
    ft_print(ft_gettime(p), "is sleeping", GREENBG, p);
    ft_usleep_gettime(p->t2sleep);
    ft_print(ft_gettime(p), "is thinking", GREENBG, p);
}

void    ft_print(long gettime, char *str, char *color, t_philo *p)
{
    printf("%s%ld ms %d %s\n",color,gettime,p->id,str);
}