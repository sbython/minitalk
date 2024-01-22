#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
void	send_bit(int pid, char *str, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 7;
		while (shift >= 0)
		{
			if ((str[i] >> shift) & 1)
            {
                ft_printf("1");
				kill(pid, SIGUSR1);
            }
			else
            {
                ft_printf("0");
				kill(pid, SIGUSR2);
            }
			shift--;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_bit(pid, str, ft_strlen(str));
	}
	else
		ft_printf("\nYOU EITHER LEFT IT BLANK OR ARE DOING MORE THAN 1 WORD\n\n");
}