/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrsirab <skrsirab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:46:01 by skrsirab          #+#    #+#             */
/*   Updated: 2023/01/24 01:30:04 by skrsirab         ###   ########.fr       */
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
    int         n_philo;
    int					t_think;
    int                 t_start;
	int					t_eat;
    int                 n_eat;
    int                 t_sleep;
    int                 t2die;
    pthread_mutex_t     *q_fork;
    pthread_mutex_t     *print;
	struct s_philo_parameter		*next;
}						t_ppar;

typedef struct s_philo
{
    t_ppar     *philo_data;
    pthread_t   philo;
    size_t      timestamp;
    int         i;
    int         id;
    int                 fork_left;
    int                 fork_right;
    struct  s_philo *next;
}                       t_philo;

void*   routine();
void*   routine2();
int	    ft_isdigit(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize);
int	    ft_atoi(const char *str);
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
void    new_philo(t_philo *philoso, t_ppar *par);
void    create_philo(t_philo *philoso, t_ppar *par);
void    inputdata(char **argv, t_ppar *par);
void    ft_forkeat(t_philo  *philoso);
void    ft_sleep(t_philo   *philoso);
void    ft_print(t_philo *philoso, char *str, char *color);
void* routines(void *phi);

# define RED "\x1b[31m"
# define BLUE "\x1b[34m"
# define GREEN "\x1b[32m"
# define WHITE "\x1b[37m"
# define CYAN "\x1b[36m"
# define MAGENTA "\x1b[35m"
# define REDBG "\x1b[41m"
# define BLUEBG "\x1b[44m"
# define GREENBG "\x1b[42m"
# define WHITEBG "\x1b[47m"
# define CYANBG "\x1b[46m"
# define MAGENTABG "\x1b[45m"


# endif