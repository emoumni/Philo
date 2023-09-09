#include "philo.h"

int main(int argc, char **argv)
{
    t_main main;
    t_philo **philos;

    if (create_philos(&main, &philos) == 0)
	{
        printf("Error concerning creating philosophers\n");
        return (1);
    }
    if (create_forks(&main, *philos) == 0) {
        printf("Error  conserning creating forks\n");
        return (1);
    }
    return (0);
}