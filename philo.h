/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrsirab <skrsirab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:46:01 by skrsirab          #+#    #+#             */
/*   Updated: 2023/01/21 20:58:54 by skrsirab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_philo_parameter
{
	int                 id;
    int					t_think;
    int                 t_start;
	int					t_eat;
    int                 n_eat;
    int                 t_sleep;
    int                 t2die;
    int                 fork_left;
    int                 fork_right;
	struct s_philo_parameter		*next;
}						t_ppar;

typedef struct s_philo
{
    t_ppar     *philo;
    int         i;
    int         n_philo;


}                       t_philo;

void*   routine();
void*   routine2();
int	    ft_isdigit(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize);
int	    ft_atoi(const char *str, char **num, t_ppar *par);
void    ft_check_argv(char **argv, t_ppar *par);
void    ft_check_argv_error(char **argv, t_ppar *par, int i);
void	ft_free(t_ppar *par);
void	ft_checkdigit(char **num);
void	ft_print_error(void);
static int	w_count(char const *s, char c);
static int	str_count(char const *s, char c);
static char	*w_chr(char const *s, char c);
char	**ft_split(char const *s, char c);
void    ft_check_error(int argc, char **argv);

# endif