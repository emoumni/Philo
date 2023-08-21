#include "philo.h"

void	cleanup(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_of_philo)
	{
		pthread_mutex_destroy(&data.forks[i]);
		pthread_mutex_destroy(&data.philos[i].lock);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	clear_data(data);
}

int validate_nb_of_arguments(int argc, char **argv)
{
    if (argc >= 5 && argc <= 6)
        return 0;
    else
        return 1;
}


int main(int argc, char **argv)
{
    t_data data;

    if (!validate_nb_of_arguments(argc, argv) || validateInput(argv) ||
        !initializeData(&data, argv, argc))
        return 1;
    if (data.nb_of_philo == 1)
        return handleCaseOne((&data));
    if (initializeThreads(&data))
        return (1);
    cleanup(&data);
    return (0);
}
