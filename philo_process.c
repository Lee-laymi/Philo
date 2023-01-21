/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrsirab <skrsirab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:45:53 by skrsirab          #+#    #+#             */
/*   Updated: 2023/01/20 23:08:42 by skrsirab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char * argv[])
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