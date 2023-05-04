#include "philo.h"

int main(int ac, char *av[])
{
    t_env       *philoenv;

    ft_check_error(ac, av);
    philoenv = malloc(sizeof(t_env));
    if (!philoenv)
        return (0);
    philoenv->sign = 0;
    philoenv->unlock_fork = 1;
	if (create_philo(av, philoenv) == 1)
        return (0); /*create thread*/
    if (philoenv->n_philo == 1)
    {
        printf("%s%d ms %d %s\n", BLUE, 0,philoenv->philo->id, "FORK");
        printf("%s%d ms %d %s\n", RED, philoenv->philo->t2die,philoenv->philo->id, "DIE");
        return (0);
    }
    if (create_mutex(philoenv) == 1)
        return (0);
	if (ft_createthread(philoenv) == 1)
        return (0);
    ft_pthread_mutex_destroy(philoenv);
    
}