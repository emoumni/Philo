/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:20:23 by emoumni           #+#    #+#             */
/*   Updated: 2023/04/22 11:20:24 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <sys/types.h>

int check(int ac, char **av)
{
    int i;

    if(ac != 3)
    {
        printf("wrong number of args");
        return(1);
    }
    i = -1;
    while(av[1][++i])
    {
        if(!ft_strchr("0123456789", av[1][i]))
        {
            printf("error");
            return(1);
        }
    }
    return(0);
}

static void send_str_bit_bit(char c, int pid)
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
        usleep(100);
    }
}

static void send_len_bit_bit(int len, int pid)
{
    int i;

    i = -1;
    while(i < 32)
    {
        if(len & 0x01)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        len = len >> 1;
        usleep(100);
    }
}

int main(int ac, char **av)
{
    int pid;
    int i;
    int len;
    char *str;

    if(check(ac, av))
        return(-1);
    pid = ft_atoi(av[1]);
    if(pid <= 0)
    {
        printf("eror consurning");
        return(-1);
    }
    str = av[2];
    len = ft_strlen(str);
    send_len_bit_bit(len, pid);
    i = -1;
    while(str[++i])
        send_str_bit_bit(str[i], pid);
        send_str_bit_bit(str[i], pid);
}