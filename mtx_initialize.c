#include "philo.h"
// Function to initialize a mutex 
int init_mutex(t_mutexdata *mutexdata)
{
    t_table *data = NULL;
    int i;

    mutexdata->forks = (pthread_mutex_t *)malloc(data->nb_philo * sizeof(pthread_mutex_t));
    if (!mutexdata->forks)
    {
        printf("Failury on allocating memory for forks");
        return (1);
    }
    i = 0;
    while (i < data->nb_philo)
    {
        if (pthread_mutex_init(&mutexdata->forks[i], NULL))
        {
            printf("Failury on initializing fork mutex");
            return (1);
        }
        i++;
    }
    if (pthread_mutex_init(&mutexdata->mutex, NULL))
    {
        printf("Failed to initialize print mutex");
        return (1);
    }
    return (0);
}

void cleanup_mutex(t_mutexdata *mutexData)
{
    t_table *data = NULL;
    int i;

    if (mutexData->forks)
    {
        i = 0;
        while (i < data->nb_philo)
        {
            pthread_mutex_destroy(&mutexData->forks[i]);
            i++;
        }
        free(mutexData->forks);
    }
    pthread_mutex_destroy(&mutexData->mutex);
}
