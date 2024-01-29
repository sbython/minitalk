/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:34:49 by msbai             #+#    #+#             */
/*   Updated: 2024/01/29 20:07:28 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	bit(int i)
{
	static char	char_bit;
	static int	num_bit;

	if (num_bit <= 7)
	{
		char_bit = char_bit << 1;
		if (i == SIGUSR1)
		{
			char_bit++;
		}
		num_bit++;
	}
	if (char_bit && num_bit > 7)
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
	}
}

int	main(void)
{
	ft_printf("PID of my server : [%d]", getpid());
	signal(SIGUSR1, bit);
	signal(SIGUSR2, bit);
	while (1)
	{
	}
	return (0);
}
