#include "philo.h"

int main(int argc, char * argv[])
{
    int x = 2;
    int pid = fork();
    if (pid == -1)
        return (1);

    if (pid == 0)
        x++;

    sleep(2);
    printf("Value if xL %d\n", x);
    printf("Process id %d\n", getpid());
    if (pid != 0)
    {
        wait(NULL);
    }
    return (0); 
}