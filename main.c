#include "philo.h"

int	main(int ac, char **av)
{
	t_table	*data;

	if (input_parsing(ac, av))
		return (1);
    data = create_empty_struct();
    if (set_struct_fields(data, ac, av) || init_mutex(data->mtx))
    {
        cleanup_mutex(data->mtx);
        return (0);
    }
	return (0);
}