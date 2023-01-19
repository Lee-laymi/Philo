#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

typedef struct s_ppara
{
	int					thinking;
    int                 start;
	int					eating;
    int                 sleep;
    int                 t2die;
	struct s_list		*next;
}						t_ppara;


void*   routine();
void*   routine2();
