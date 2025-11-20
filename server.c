/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:12:55 by slayer            #+#    #+#             */
/*   Updated: 2025/11/20 18:44:44 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
# define WAIT_TIME 700

void    disp(int sig)
{
    static char tracker;
    printf("%d", (sig));
    if (tracker++ / 7)
    {
        tracker = 0;
        printf("|");
    }
    usleep(100000);
}

int	ft_recur_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 && nb != 0)
		return (1);
	else
		return (nb * ft_recur_power(nb, power - 1));
}

/* static void	ft_restart_var(int *len_rec, char **str, int *s)
{
	*len_rec = 0;
	if (str)
	{
		printf("%s\n", *str);
		free(*str);
		*str = 0;
	}
	*s = 0;
} */

static void	str_len(int *curr_bit_len, int *len, int sig)
{
	if (sig == SIGUSR2)
	{
		disp(1);
		*len = *len | 1;
	}
	else
		disp(0);
	(*curr_bit_len)++;
	if (*curr_bit_len == 32)
	{
		(printf("\nbit_len= %d\n",*len));
		return ;
	}
	*len = *len << 1;
}

static void	ft_signal(int sig)
{
	static int	curr_bit_len;
	static int	len;

	if(curr_bit_len < 32)
		return (str_len(&curr_bit_len, &len, sig));
	
	
}

int	main(void)
{
	printf("PID=%d\n", getpid());
	signal(SIGUSR1, &ft_signal);
	signal(SIGUSR2, &ft_signal);
	while (1)
		usleep(WAIT_TIME);
	return (0);
}
