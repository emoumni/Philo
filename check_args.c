#include "philo.h"

int	ft_atoi(const char *str)
{
	long			res;
	long			sign;
	unsigned int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t'
		||str[i] == '\n' || str[i] == '\f' || str[i] == '\r')
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return ((int)(res * sign));
}

int input_parsing(int ac, char **av)
{
    int iteration;
	
	if (ac != 5 && ac != 6)
	{
        error_in();
        return (1);
    }
    iteration = 1;
    while (iteration < ac)
	{
        if (valid_input(av[iteration]))
		{
            error_in();
            return (1);
        }
        iteration++;
    }
    return (0);
}
