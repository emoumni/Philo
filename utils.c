#include "philo.h"


void error_in() {
    printf("%s\n", "Error");
}


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while(s[i])
		i++;
	return (i);
}

int valid_input(const char *num_str)
{
    int i;
	int num;

	if (!num_str)
        return (1);
    i = 0;
    if (!ft_isdigit(num_str[i]))
        return (1); // Return 1 for non-numeric characters (invalid)
    while (num_str[i] != '\0') // Move to the end of the string to check for non-digit characters
	{
        if (!ft_isdigit(num_str[i]))
            return 1;  // Return 1 for non-numeric characters (invalid)
        i++;
    }
    num = 0;
    i = 0;
    while (num_str[i] != '\0') // Convert the string to an integer
	{
        num = num * 10 + (num_str[i] - '0');
        i++;
    }
    // Check if the integer is negative
    if (num < 0)  // Check if the integer is negative
        return (1);  // Return 1 for negative integers (invalid)
    return (0);  // Return 0 for a valid positive integer
}
