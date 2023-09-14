#include "philo.h"

void    initialize_philo(t_philo *philo, size_t i, size_t left, size_t right) {
    philo->id = i;
    philo->eat_count = 0;
    philo->last_meal = 0;
    philo->left_fork = left;
    philo->right_fork = right;
}

int create_philos(t_table *main_data, t_philo **philos)
{
    size_t i;
    size_t left;
    size_t right;

    *philos = (t_philo *)malloc(sizeof(t_philo) * main_data->nb_philo);
    if (*philos == NULL)
        return (0);
    i = 0;
    while (i < main_data->nb_philo)
    {
        left = i;
        right = (i + 1) % main_data->nb_philo;
        initialize_philo(&(*philos)[i], i + 1, left, right);
        i++;
    }
    return (1);
}
