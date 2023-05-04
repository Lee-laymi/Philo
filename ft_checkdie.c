#include "philo.h"

int	ft_check_time(t_philo *p)
{
	long	time_now;
	int		i;

	i = 1;
	while (i <= p->env->n_philo)
	{
		time_now = ft_getCurrentTime();
		if (time_now - p->cur_t2eat >= (long)p->t2die)
		{
			 ft_print(ft_gettime(p),"DIE" , REDBG, p);
			 p->env->sign = 1;
			 return (1);
		}
		p = p->next;
	}
	return (0);
}

void*     ft_checkdie(void *p)
{
    t_philo   *philo;

    philo = (t_philo *)p;
    while (1)
    {
		if (ft_check_time(p) == 1)
			break ;
    }
	while (philo->env->unlock_fork)
		ft_unlock_fork(philo);
    return (NULL);
}