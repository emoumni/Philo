#include "philo.h"

int create_forks(maindata *main_data, philosopher *philosopher_data)
{
    int i;
    pthread_mutex_t *forks;

    i = 0;
    forks = malloc(sizeof(pthread_mutex_t) * main_data->num_philo);
    if (forks == NULL)
        return (0);    
    while (i < main_data->num_philo)
    {
        if (pthread_mutex_init(&forks[i], NULL) != 0)
        {
            while (i > 0)
            {
                i--;
                pthread_mutex_destroy(&forks[i]);
            }
            free(forks);
            return (0);
        }
        i++;
    }
    philosopher_data->forks = forks;
    return (1);
}

void destroy_forks(philosopher *philosopher_data) {
    int i;
    maindata main_data;

    i = 0;
    while (i < main_data.num_philo)
    {
        pthread_mutex_destroy(&philosopher_data->forks[i]);
        i++;
    }
    free(philosopher_data->forks);
}

void unlock_forks(philosopher *philosopher_data)
{
    int i;
    maindata main_data;

    i = 0;
    while (i < main_data.num_philo)
    {
        pthread_mutex_unlock(&philosopher_data->forks[i]);
        i++;
    }
}
