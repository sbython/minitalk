/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:34:55 by msbai             #+#    #+#             */
/*   Updated: 2024/01/29 19:58:21 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
int ft_ifnmb(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(!ft_isdigit(str[i]))
			return(0);
		i++;
	}
	return (1);
}
void get_bet(int pid , char ch)
{
	int		shift;
	shift = 7;
		while (shift >= 0)
		{
			if ((ch >> shift) & 1)
            {
				kill(pid, SIGUSR1);
            }
			else
            {
				kill(pid, SIGUSR2);
            }
			shift--;
			usleep(150);
		}
}
void	send_bit(int pid, char *str)
{
	
	size_t	i;

	i = 0;
	while (str[i])
	{
		get_bet(pid , str[i]);
		i++;
	}
	get_bet(pid , str[i]);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		if(!ft_ifnmb(argv[1]))
			return(ft_printf("mnitak mdakhal 7arf wast pid") ,0);
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_bit(pid, str);
		
	}
	else
		ft_printf("we need only 3 argument\n");
}