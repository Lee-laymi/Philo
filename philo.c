# include "philo.h"

int x=0;
void*   routine()
{
    x++;
    sleep(2);
    printf("value of x: %d\n", x);
}

void*   routine2()
{
    x++;
    sleep(2);
    printf("value of x: %d\n", x);
}

int main(int argc, char* argv[])
{
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, & routine, NULL) != 0)
        return (1);
    if (pthread_create(&t2, NULL, & routine, NULL) != 0)
        return (2);
    if (pthread_join(t1, NULL) != 0)
        return (3);
    if (pthread_join(t2, NULL) != 0)
        return (3);
    return (0);
}