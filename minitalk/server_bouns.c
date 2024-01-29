/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bouns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:34:49 by msbai             #+#    #+#             */
/*   Updated: 2024/01/29 17:21:41 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

void bit(int i,  siginfo_t *info, void *context)
{
    static char char_bit ;
    static int num_bit;
    (void) context;
    if(num_bit <= 7) 
    {   
        char_bit = char_bit << 1;
        if (i == SIGUSR1)
        {
            char_bit++;
        }
        num_bit++;
    }
   if(char_bit && num_bit > 7) 
    {
        ft_printf("%c", char_bit);
        char_bit = 0;
        num_bit = 0;
    }
    else if (!char_bit && num_bit > 7)
    {
        ft_printf("\n");
        char_bit = 0;
        num_bit = 0;
        kill(info->si_pid, SIGUSR1);
    }
}

int main(void)
{
    struct sigaction sa;
    
    sa.sa_sigaction = bit;
    sa.sa_flags = SA_SIGINFO;
    ft_printf("PID of my server : [%d]", getpid() );
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2,  &sa, NULL);
    while (1) 
    {
        usleep(0);
    }
    return (0);
}