#include "philo.h"

void initialize_philo(philosopher *philo, int id, int left, int right) {
    philo->id = id;
    philo->num_of_times_ate = 0;
    philo->time_to_die = 0;
    philo->left_fork = left;
    philo->right_fork = right;
}

int create_philos(maindata *main_data, philosopher **philos)
{
    int i;
    int left;
    int right;

    *philos = malloc(sizeof(philosopher) * main_data->num_philo);
    if (*philos == NULL)
        return (0);
    i = 0;
    while (i < main_data->num_philo)
    {
        left = i;
        right = (i + 1) % main_data->num_philo;
        initialize_philo(&(*philos)[i], i + 1, left, right);
        i++;
    }
    return (1);
}
