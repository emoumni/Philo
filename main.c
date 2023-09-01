#include "philo.h"

int	main(int argc, char *argv[])
{
	maindata	main;
    philosopher **philos;

	if (create_philos(&main, philos) == 0)
		return (1);
	if (create_forks(&main, *philos) == 0)
		return (1);
	return (0);
}