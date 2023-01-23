/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrsirab <skrsirab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:45:46 by skrsirab          #+#    #+#             */
/*   Updated: 2023/01/24 01:08:44 by skrsirab         ###   ########.fr       */
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
    t_philo     *philoso;
    t_ppar      *par;
    int         i;

	par = malloc(sizeof(t_ppar));
	if (par == NULL)
		return (0);
   // ft_check_error(argc, argv);
/*initialize philo parameter*/

    inputdata(argv, par);
    create_philo(philoso, par);
/*while loop*/
    while (philoso != NULL)
    {
        pthread_create(&philoso->philo, NULL, &routines, &philoso);
        philoso = philoso->next;
    }
/* create Thread & run philo in routines */

    printf(" Hello! \n");

}

void    new_philo(t_philo *philoso, t_ppar *par)
{
    philoso->philo_data = par;
    philoso->philo = malloc(sizeof(pthread_t));
    philoso->next = NULL;
}
 
void    create_philo(t_philo *philoso, t_ppar *par)
{
    int     i;

    i = 0;
    while (i < par->n_philo)
    {
        philoso = malloc(sizeof(t_philo));
        new_philo(philoso, par);
        philoso->id = i + 1;
        philoso->fork_left = philoso->id - 1;
        philoso->fork_right = philoso->id % par->n_philo;
        printf("Philo id ==> %d\n",philoso->id);
        philoso = philoso->next;
        // printf("n_philo : %d\n", philoso->n_philo);
        i++;
    }
}

void    inputdata(char **argv, t_ppar *par)
{
    par->t2die = ft_atoi(argv[2]);
    par->t_eat = ft_atoi(argv[3]);
    par->t_sleep = ft_atoi(argv[4]);
    if (argv[5])
        par->n_eat = ft_atoi(argv[5]); /*taa mee*/
    else
        par->n_eat = 0;
    par->q_fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
    par->n_philo = ft_atoi(argv[1]);
}