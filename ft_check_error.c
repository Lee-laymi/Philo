/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrsirab <skrsirab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:12:44 by skrsirab          #+#    #+#             */
/*   Updated: 2023/01/21 21:09:34 by skrsirab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_check_error(int argc, char **argv)
{
     	int     i;
		int		j;
		int		k;

        i = 0;
		j = 0;
		k = 0;

		if (argc != 4 || argc != 5)
		{
			write(2, "Incorrect no of input!\n", 6);
			exit (0);
		}	

        while (argc[k])
        {
			printf("test1\n");
             while (argv[j][i])
			{
				j = 0;
				printf("test2\n");
			if (argv[j][i] == '-' && argv[j][i] == '+' && (argv[j][i + 1] < 48
					|| argv[j][i + 1] > 57))
				ft_print_error();
			else if ((argv[j][i] < 48 || argv[j][i] > 57) && argv[j][i] != ' ' \
					&& argv[j][i] != '-' && argv[j][i] != '+')
				ft_print_error();
			j++;
			printf("test3\n");
			}
        i++;
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

void	ft_free(t_ppar *par)
{
	t_ppar	*tmp_par;

	while (par)
	{
		tmp_par = par;
		par = par->next;
		free(tmp_par);
	}
}

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