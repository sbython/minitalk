#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

static char char_bit ;

void bit(int i)
{
    static int num_bit = 0;
    if(num_bit <= 7)
    {   
        char_bit = char_bit << 1;
        if (i == SIGUSR1)
        {
            ft_printf("1");
            char_bit++;
        }
        if (i == SIGUSR2)
            ft_printf("0");
        num_bit++;
    }
   else if(num_bit == 7) 
    {
        ft_printf("%c", char_bit);
        num_bit = 0;
    }
    else 
    {
        ft_printf("\n");
        num_bit = 0;
    }

}

int main(void)
{
    pid_t pid = getpid();
    ft_printf("PID of my server : [%d]", pid );

    while (1) {
        signal(SIGUSR1, bit);
        signal(SIGUSR2, bit);
		//pause();
        // usleep(300); // Sleep for 1 second or do some other work
    }
    return (0);
}