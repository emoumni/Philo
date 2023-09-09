#include "philo.h"

void    initialize_philo(t_philo *philo, size_t id, size_t left, size_t right) {
    philo->position = id;
    philo->meals = 0;
    philo->threshold = 0;
    philo->left_fork = left;
    philo->right_fork = right;
}

int create_philos(t_main *main_data, t_philo **philos)
{
    size_t i;
    size_t left;
    size_t right;

    *philos = (t_philo *)malloc(sizeof(t_philo) * main_data->amount);
    if (*philos == NULL)
        return (0);
    i = 0;
    while (i < main_data->amount)
    {
        left = i;
        right = (i + 1) % main_data->amount;
        initialize_philo(&(*philos)[i], i + 1, left, right);
        i++;
    }
    return (1);
}
