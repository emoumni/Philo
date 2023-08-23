/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:26:47 by emoumni           #+#    #+#             */
/*   Updated: 2023/04/23 16:26:52 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <math.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int err(int ac, char **av)
{
    int i;

    if(ac != 3)
    {
        printf("wrong number of args")
        return(1);
    }
    i = -1;
    while(av[1][++i])
    {
        if(!ft_strchr("0123456789", av[1][i]))
        {
            printf("eroor");
            return(1);
        }
    }
    return(0);
}

void send_str(int pid; char c)
{
    int i;

    i = -1;
    while(++i < 8)
    {
        if(c & 0x01)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        c = c >> 1;
        usleep(200);
    }
}

void send_len(int pid, int len)
{
    int i;

    i = -1;
    while(++i < 32)
    {
        if(c & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        len = len >> 1;
        usleep(200);
    }
}

int main(int ac, char **av)
{
    int i;
    int len;
    int pid;
    char *str;

    if(eroor(ac, av))
        return(-1);
    pid = ft_atoi(av[1]);
    if(pid <= 0)
    {
        printf("error consurning pid");
        return(-1);
    }
    str = av[2];
    len = ft_strlen(str);
    send_len(pid, len);
    i = -1;
    while(str[++i])
        send_str(pid, str[i]);
        send_str(pid, str[i]);
}