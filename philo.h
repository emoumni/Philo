#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <signal.h>

typedef struct s_philo
{
	int				id;
	int				finished;
	int				eat_count;
	long			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_table	*table;
}					t_philo;

typedef struct s_mutex 
{
    pthread_mutex_t		*forks;
    pthread_mutex_t		mutex;
}				t_mutexdata;

typedef struct s_table
{
	int				nb_philo;
	int				nb_of_each_must_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	long			start_time;
	int				has_dead;
	pthread_t		*threads;
	t_philo			*philos;
	t_mutexdata		*mtx;
}					t_table;

//parsing
void		error_in();
int			ft_isdigit(int c); 
int			ft_strlen(char *s);
int			valid_input(const char *num_str);
int			input_parsing(int ac, char **av);
int			ft_atoi(const char *str);
//initialize
int			set_struct_fields(t_table *data, int ac, char **av);
t_table		*create_empty_struct();
int			init_mutex(t_mutexdata *mutexdata);
void		cleanup_mutex(t_mutexdata *mutexData);

//creat threads



#endif
