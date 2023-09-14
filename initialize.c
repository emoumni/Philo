#include "philo.h"

t_table *create_empty_struct()
{
    t_table *data = (t_table *)malloc(sizeof(t_table));
    if (!data)
        return (NULL);
    data->philos = NULL;
    data->mtx->forks = NULL;
    data->philos->finished = 0;
    return (data);
}

int set_struct_fields(t_table *data, int ac, char **av)
{
    if (ac > 1)
        data->nb_philo = ft_atoi(av[1]);
    else
        data->nb_philo = 0;
    if (ac > 2)
        data->time_to_die = ft_atoi(av[2]);
    else
        data->time_to_die = 0;
    if (ac > 3)
        data->time_to_eat = ft_atoi(av[3]);
    else
        data->time_to_eat = 0;
    if (ac > 4)
        data->time_to_sleep = ft_atoi(av[4]);
    else
        data->time_to_sleep = 0;
    if (ac == 5)
        data->nb_of_each_must_eat = -1;
    else 
    {
        if (ac > 5)
            data->nb_of_each_must_eat = ft_atoi(av[5]);
        else
            data->nb_of_each_must_eat = 0;
    }
    return (0);
}
