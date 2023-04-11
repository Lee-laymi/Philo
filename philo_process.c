/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:45:53 by skrsirab          #+#    #+#             */
/*   Updated: 2023/03/10 17:38:17 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_process(int ac, char *av[])
{
    
    int x = 2;
    int pid = fork();
    if (pid == -1)
        return (1);

    if (pid == 0)
        x++;

    sleep(2);
    printf("Value if xL %d\n", x);
    printf("Process id %d\n", getpid());
    if (pid != 0)
    {
        wait(NULL);
    }
    return (0); 
}