/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slayer <slayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:12:55 by slayer            #+#    #+#             */
/*   Updated: 2025/11/19 21:01:13 by slayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
# define WAIT_TIME 700

int	ft_recur_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 && nb != 0)
		return (1);
	else
		return (nb * ft_recur_power(nb, power - 1));
}

static void	str_len(int *curr_bit, char **str, int *rec, int j)
{
	static int	len_val = 0;

	if (j == SIGUSR2)
		len_val += ft_recur_power(2, *curr_bit);
	if (*curr_bit == 31)
	{
		*rec = 1;
		*str = calloc(len_val + 1, sizeof(char));
		*curr_bit = 0;
		len_val = 0;
		return ;
	}
	(*curr_bit)++;
}

static void	ft_restart_var(int *len_rec, char **str, int *s, int client_pid)
{
	*len_rec = 0;
	if (str)
	{
		printf(*str, 1);
		free(*str);
		*str = 0;
	}
	*s = 0;
	kill(client_pid, SIGUSR1);
}

static void	ft_signal(int sig)
{
	static int		char_val = 0, curr_bit = 0, i = 0, len = 0;
	static char		*final_str;
	static pid_t	client_pid;

	if (!len)
		str_len(&curr_bit, &final_str, &len, sig);
	else
	{
		if (sig == SIGUSR2)
			char_val += ft_recur_power(2, curr_bit);
		if (curr_bit == 7)
		{
			final_str[i++] = char_val;
			curr_bit = 0;
			if (char_val == 0)
				return (ft_restart_var(&len, &final_str, &i, client_pid));
			char_val = 0;
			return ;
		}
		curr_bit++;
	}
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
