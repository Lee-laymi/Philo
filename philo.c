#include "philo.h"

int main(int ac, char *av[])
{
    t_env       *philoenv;

    ft_check_error(ac, av);
    philoenv = malloc(sizeof(t_env));
    if (!philoenv)
        return (0);
	create_philo(av, philoenv); /*create thread*/
    if (create_mutex(philoenv) == 1)
        return (0);
	ft_createthread(philoenv);

/* create Thread & run philo in routines */
}

int     create_mutex(t_env *philoenv)
{
        int     i;
        t_philo *tmp;
        
        i = 0;
        tmp = philoenv->philo;
        while (i < philoenv->n_philo)
        { 
            if (pthread_mutex_init(&tmp->mutex_fork, NULL) != 0)
                return (1);
            tmp = tmp->next;
            i++;
        }
        return (0);
}

void    create_philo(char **av, t_env *philoenv)
{
        int     i;
        t_philo *tmp_philo;
        t_philo *tmp_head;

        i = 1;
		philoenv->n_philo = ft_atoi(av[1]);
        philoenv->philo = malloc(sizeof(t_philo));
        if (!philoenv->philo)
            return ;
        tmp_philo = philoenv->philo;
        tmp_head = philoenv->philo;
        while (i <= philoenv->n_philo)
        {
            tmp_philo->id = i;
            ft_addphilo(tmp_philo, av, philoenv);
            tmp_philo = tmp_philo->next;
            i++;
        }
        // if (philoenv->n_philo > 1)
            tmp_philo->next = tmp_head;
        // else 
        //     tmp_philo->next = NULL;
}

void    ft_addphilo(t_philo *p,char **av, t_env *philoenv)
{
        if (av[5])
        	p->n2eat = ft_atoi(av[5]); /*taa mee*/
    	else
        	p->n2eat = 0;
        p->t2die = ft_atoi(av[2]);
        p->t2eat = ft_atoi(av[3]);
        p->t2sleep = ft_atoi(av[4]);
        p->env = philoenv;
        p->next = malloc(sizeof(t_philo));
        if (!p->next)
            return ;
        
}

void     ft_createthread(t_env *philoenv)
    {
        int     i;
		t_philo *tmp_thread;

        i = 0; 
        tmp_thread = philoenv->philo;
        philoenv->timestamp = ft_getCurrentTime();
        ft_create_odd(tmp_thread);
        usleep(50);
        tmp_thread = philoenv->philo;
        ft_create_even(tmp_thread);
        tmp_thread = philoenv->philo;
        if (pthread_create(&(philoenv->checker), NULL, &ft_checkdie, tmp_thread) != 0)
            return ;
        while ( i < philoenv->n_philo)
        {
            if(pthread_join(tmp_thread->thread, NULL) != 0)
                return ;
            tmp_thread = tmp_thread->next;
            i++;
        }
        if(pthread_join(philoenv->checker, NULL) != 0)
            return ;
    }

void*     ft_checkdie(void *p)
{
    t_philo   *philo;

    philo = p;
    while ((ft_getCurrentTime() - (philo->cur_t2eat)) < philo->t2die)
    {
        if (philo->env->n_philo > 1)
            philo = philo->next;
        usleep(50);
    }
    printf("new_env %d\n",philo->id);
    return (0);
}

long     ft_getCurrentTime(void)
{
        struct timeval currentTime;

        gettimeofday(&currentTime, NULL);
        return (currentTime.tv_sec * 1000) + (currentTime.tv_usec / 1000);
}

void     ft_usleep_gettime(int timestamp)
{
    long    get_timestamp;

    get_timestamp = ft_getCurrentTime();
    while (ft_getCurrentTime() - get_timestamp < (long) timestamp)
        usleep(50); 
}

long    ft_gettime(t_philo *philo)
{
    long    t;

    t = ft_getCurrentTime();
    return(t - (philo->env->timestamp));
}

void    ft_create_odd(t_philo *tmp_thread)
{
        int         i;
        t_philo     *tmp1;

        i = 1;
        tmp1 = tmp_thread;
        while (i <= tmp_thread->env->n_philo)
        {
            if (pthread_create(&(tmp1->thread), NULL, &routines, tmp1) != 0)
                return ;
            usleep(5);
            tmp1 = tmp1->next->next;
            i = i + 2;
        }
}

void    ft_create_even(t_philo *tmp_thread)
{
        int         i;
        t_philo     *tmp2;

        i = 2;
        tmp2 = tmp_thread->next;
        while (i <= tmp_thread->env->n_philo)
        {
            if (pthread_create(&(tmp2->thread), NULL, &routines, tmp2) != 0)
                return ;
            usleep(5);
            tmp2 = tmp2->next->next;
            i = i + 2;
        }
}
