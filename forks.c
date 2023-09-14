#include "philo.h"

int create_forks(t_table *main_data)
{
    int i;
    pthread_mutex_t *fork;

    i = 0;
    fork = malloc(sizeof(pthread_mutex_t) * main_data->nb_philo);
    if (fork == NULL)
        return (0);    
    while (i < main_data->nb_philo)
    {
        if (pthread_mutex_init(&fork[i], NULL) != 0)
        {
            while (i > 0)
            {
                i--;
                pthread_mutex_destroy(&fork[i]);
            }
            free(fork);
            return (0);
        }
        i++;
    }
    main_data->mtx->forks = fork;
    return (1);
}

void destroy_forks(t_table *philosopher_data)     
{
    int i;
    t_philo main_data;

    i = 0;
    while (i < main_data.id)
    {
        pthread_mutex_destroy(&philosopher_data->mtx->forks[i]);
        i++;
    }
    free(philosopher_data->mtx->forks);
}

void unlock_forks(t_table *philosopher_data)
{
    int i;
    t_philo main_data;

    i = 0;
    while (i < main_data.id)
    {
        pthread_mutex_unlock(&philosopher_data->mtx->forks[i]);
        i++;
    }
}
