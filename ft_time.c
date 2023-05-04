#include "philo.h"

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