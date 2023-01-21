/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrsirab <skrsirab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:45:46 by skrsirab          #+#    #+#             */
/*   Updated: 2023/01/21 20:59:26 by skrsirab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int x=0;
// void*   routine()
// {
//     x++;
//     sleep(2);
//    // printf("value of x: %d\n", x);
// }

// void*   routine2()
// {
//     x++;
//     sleep(2);
//     //printf("value of x: %d\n", x);
// }

int main(int argc, char* argv[])
{
    // t_philo     *philo;
    // t_ppar      *par;

	// par = malloc(sizeof(t_philo));
	// if (par == NULL)
	// 	return (0);

    ft_check_error(argc, argv);
    printf(" Hello! \n");

    // pthread_t t1, t2;
    // if (pthread_create(&t1, NULL, & routine, NULL) != 0)
    //     return (1);
    // if (pthread_create(&t2, NULL, & routine, NULL) != 0)
    //     return (2);
    // if (pthread_join(t1, NULL) != 0)
    //     return (3);
    // if (pthread_join(t2, NULL) != 0)
    //     return (3);
    // return (0);
}