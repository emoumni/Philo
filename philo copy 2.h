#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>


typedef struct s_philo
{
    struct s_data *data;
    pthread_t t1;
    int id;
    int eat_cont;
    int status;
    int eating;
    uint64_t time_to_die;
    pthread_mutex_t lock;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
} t_philo;

typedef struct s_data
{
    pthread_t *tid;
    int nb_of_philo;
    int nb_of_meals;
    int is_dead;
    int finish;
    t_philo *philos;
} t_data;

typedef struct s_time
{
    struct s_data *data;
    u_int64_t time_of_death;
    u_int64_t time_of_eat;
    u_int64_t time_of_sleep;
    u_int64_t time_of_start;
} t_time;

typedef struct s_mutex
{
    struct s_data *data;
    pthread_mutex_t *forks;
    pthread_mutex_t lock;
    pthread_mutex_t write;
} t_mutex;


#endif
