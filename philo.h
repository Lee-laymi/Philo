/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ami <ami@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:34:54 by skrairab          #+#    #+#             */
/*   Updated: 2023/04/24 22:53:32 by ami              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>

typedef struct s_philo_parameter
{    
    int                 id;   
    int					t2think;
    int                 t2start;
	int					t2eat;
    int                 n2eat;
    int                 t2sleep;
    int                 t2die;
    int                 fork_right; /*friend*/
    long                cur_t2eat;
    pthread_t           thread;
    pthread_mutex_t     mutex_fork; /*owner*/
    pthread_mutex_t     *print;
    struct s_env        *env;
    struct timeval      currentTime;
    struct timeval      t;
	struct s_philo_parameter		*next;
}						t_philo;

typedef struct s_env
{
    t_philo     *philo;
    pthread_t   checker;
    long        timestamp;
    int         n_philo;
    int         i;
}                       t_env;

int	    ft_isdigit(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize);
int	    ft_atoi(const char *str);
void    ft_check_argv(char **argv, t_env *p);
void    ft_check_argv_error(char **argv, t_env *p, int i);
void	ft_free(t_env *p);
void	ft_checkdigit(char **num);
void	ft_print_error(void);
static int	w_count(char const *s, char c);
static int	str_count(char const *s, char c);
static char	*w_chr(char const *s, char c);
char	**ft_split(char const *s, char c);
void    ft_check_error(int argc, char **argv);
void    new_philo(t_env *philoso);
void    create_philo(char **av, t_env *philoenv);
void    init_data(char **argv, t_env *p);
void    ft_forkeat(t_philo  *p);
void    ft_sleep(t_philo   *p);
void    ft_print(long gettime, char *str, char *color, t_philo *p);
void	*routines(void *phi);
int 	philo_process(int ac, char *av[]);
int     create_mutex(t_env *philoenv);
void     ft_createthread(t_env *philoenv);
long     ft_getCurrentTime(void);
void    ft_usleep_gettime(int timestamp);
long    ft_gettime(t_philo *philo);
void    ft_create_odd(t_philo *tmp_thread);
void    ft_create_even(t_philo *tmp_thread);
void*     ft_checkdie(void *env);
void    ft_addphilo(t_philo *p,char **av, t_env *philoenv);

# define RED "\x1b[31m"
# define BLUE "\x1b[34m"
# define GREEN "\x1b[32m"
# define WHITE "\x1b[37m"
# define CYAN "\x1b[36m"
# define MAGENTA "\x1b[35m"
# define REDBG "\x1b[41m"
# define BLUEBG "\x1b[144m"
# define GREENBG "\x1b[142m"
# define WHITEBG "\x1b[147m"
# define CYANBG "\x1b[46m"
# define MAGENTABG "\x1b[45m"


# endif