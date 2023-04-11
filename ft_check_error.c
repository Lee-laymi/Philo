/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:12:44 by skrsirab          #+#    #+#             */
/*   Updated: 2023/03/28 14:11:35 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_check_error(int ac, char **av)
{
     	int     i;
		int		j;
		int		k;

        i = 1;
		k = 0;
		if (ac != 5 && ac != 6)
			ft_print_error();	
		while (av[i])
		{
			ft_checkdigit(&av[i]);
			if (ft_atoi(av[i]) > INT_MAX)
				ft_print_error();
			i++;
		}
		if (ac == 5)
		{
			if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) < 0|| ft_atoi(av[3]) < 0 || ft_atoi(av[4]) < 0)
			{
				printf("Hello check error3\n");
				printf("av[1]%d\n", ft_atoi(av[1]));
				printf("av[2]%d\n", ft_atoi(av[2]));
				printf("av[3]%d\n", ft_atoi(av[3]));
				printf("av[4]%d\n", ft_atoi(av[4]));
				//printf("av[5]%d\n", ft_atoi(av[5]));
				ft_print_error();
				printf("Hello check error4\n");
			} 
		}
		else if (ac == 6)
			{
				if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) < 0|| ft_atoi(av[3]) < 0 || ft_atoi(av[4]) < 0 || ft_atoi(av[5]) < 0)
				{
					printf("Hello check error5\n");
					printf("av[1]%d\n", ft_atoi(av[1]));
					printf("av[2]%d\n", ft_atoi(av[2]));
					printf("av[3]%d\n", ft_atoi(av[3]));
					printf("av[4]%d\n", ft_atoi(av[4]));
					printf("av[5]%d\n", ft_atoi(av[5]));
					ft_print_error();
					printf("Hello check error6\n");
				}
			}
}


// void    ft_check_argv_error(char **argv, t_ppar *par, int i)
// {
//     if (argv[i][0] == '\0')
//     {
//         ft_free(par);
//         exit (0);
//     }
// }

// void	ft_free(t_env *p)
// {
// 	t_env	tmp_par;

// 	while (p->parameter)
// 	{
// 		tmp_par = p->parameter;
// 		p->parameter = p->parameter->next;
// 		free(tmp_par);
// 	}
// }

void	ft_checkdigit(char **num)
{
	int		c;
	int		d;

	c = 0;
	while (num[c])
	{ 
		d = 0;
		while (num[c][d])
		{
			if (num[c][d] == '-' && num[c][d] == '+' && (num[c][d + 1] < 48
					|| num[c][d + 1] > 57))
				ft_print_error();
			else if ((num[c][d] < 48 || num[c][d] > 57) && num[c][d] != ' ' \
					&& num[c][d] != '-' && num[c][d] != '+')
				ft_print_error();
			d++;
		}
		c++;
	}
}

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}