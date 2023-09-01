#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <signal.h>

typedef struct {
    int id;
    int num_of_times_ate;
    int time_to_die;
    int left_fork;
    int right_fork;
    pthread_mutex_t *forks;
} philosopher;

typedef struct {
    int num_philo;
} maindata;


//parsing



//initialize
void initialize_philo(philosopher *philo, int id, int left, int right);
int create_philos(maindata *main_data, philosopher **philos);
int create_forks(maindata *main_data, philosopher *philosopher_data);


//creat threads



#endif
