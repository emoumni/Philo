#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <signal.h>

typedef struct s_actions {
    char *name;
} t_actions;

typedef struct s_main;

typedef struct s_philo {
    size_t position;
    size_t left_fork;
    size_t right_fork;
    size_t meals;
    size_t eating;
    size_t last_meal;
    size_t threshold;
    struct s_main *instance;
} t_philo;

typedef struct s_main {
    size_t amount;
    size_t time_toeat;
    size_t time_todie;
    size_t time_tosleep;
    size_t repas;
    size_t finish;
    t_philo *philosophers;
    int *forks;
    pthread_mutex_t write_mutex;
    pthread_mutex_t *frks_mutexes;
    pthread_mutex_t die_mutex;
} t_main;

t_actions actions[] = {
    {"TAKING_FORK"},
    {"EATING"},
    {"SLEEPING"},
    {"THINKING"},
    {"DIED"},
    {"OVER"}
};

//parsing



//initialize



//creat threads



#endif
