/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:53:40 by skrsirab          #+#    #+#             */
/*   Updated: 2023/05/05 17:28:34 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routines(void *phi)
{
    t_philo *p;

    p = phi;
    p->cur_t2eat = ft_getCurrentTime();
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

int ft_forkeat(t_philo  *p)
{
    if (p->env->sign == 1)
        return (1);
    pthread_mutex_lock(&p->next->mutex_fork);
    if (p->env->sign == 1)
        return (1);
    pthread_mutex_lock(&p->mutex_fork);
    if (p->env->sign == 1)
        return (1);
    ft_print(ft_gettime(p),"Fork right" , GREEN, p);
    ft_print(ft_gettime(p),"Fork left" , BLUE, p);
    ft_print(ft_gettime(p),  "is eating", CYAN, p);
    ft_usleep_gettime(p->t2eat);
    p->n2eat_check = p->n2eat_check + 1;
    printf("n2eat_check %d == %d\n",p->id, p->n2eat_check);
    p->cur_t2eat = ft_getCurrentTime();
    pthread_mutex_unlock(&p->next->mutex_fork);
    if (p->env->sign == 1)
        return (1);
    pthread_mutex_unlock(&p->mutex_fork);
    if (p->env->sign == 1)
        return (1);
    return (0);
/* print va philo has taken fork + time stamp */
/* update num of eat */
}

int ft_sleep(t_philo   *p)
{
    if (p->env->sign == 1)
        return (1);
    ft_print(ft_gettime(p), "is sleeping", WHITE, p);
    ft_usleep_gettime(p->t2sleep);
    if (p->env->sign == 1)
        return (1);
    ft_print(ft_gettime(p), "is thinking", MAGENTA, p);
    return (0);
}

void    ft_print(long gettime, char *str, char *color, t_philo *p)
{
    printf("%s%ld ms %d %s\n",color,gettime,p->id,str);
}