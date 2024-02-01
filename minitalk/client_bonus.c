/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bouns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:34:55 by msbai             #+#    #+#             */
/*   Updated: 2024/01/29 22:19:23 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int	ft_ifnmb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	get_bet(int pid, char ch)
{
	int	shift;

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
		get_bet(pid, str[i]);
		i++;
	}
	get_bet(pid, str[i]);
}

void	msg_sent(int i)
{
	(void)i;
	ft_printf("your msg is sent!!");
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	signal(SIGUSR1, msg_sent);
	if (argc == 3)
	{
		if (!ft_ifnmb(argv[1]))
			return (ft_printf("mnitak mdakhal 7arf wast pid"), 0);
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_bit(pid, str);
	}
	else
		ft_printf("\n we need only 3 argument\n\n");
}
