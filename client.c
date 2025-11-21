/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:06:07 by slayer            #+#    #+#             */
/*   Updated: 2025/11/21 02:42:07 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile	sig_atomic_t g_ack = 0;

int	ft_strlen(const char *c)
{
	int	len;

	len = 0;
	while (c[len] != '\0')
	{
		len++;
	}
	return (len);
}

static int	pid_parser(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

static void	ft_s_strlen_bit_bit(int len, int pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		g_ack = 0;
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		i++;
		while(g_ack == 0)
			sleep(1);
	}
}

static void	send_nextchar_bit_bit(unsigned char len, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		g_ack = 0;
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		while(g_ack == 0)
			sleep(1);
	}
}

static void	ft_signal(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
	else if (sig == SIGUSR2)
	{
		write(1,"the message was receved!",25);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	len;
	int	i;
	char *str;

	if (argc != 3)
		return (write(2, "Usage: ./client <pid> <string>\n", 32), -1);
	if (pid_parser(argv[1]))
		return (write(2, "<pid> must be all numerical and positive\n", 42), -1);
	len = ft_strlen(argv[2]);
	pid = atoi(argv[1]);
	signal(SIGUSR1, &ft_signal);
	signal(SIGUSR2, &ft_signal);
	ft_s_strlen_bit_bit((len), pid);
	str = argv[2];
	i = 0;
	while (str[i])
	{
		send_nextchar_bit_bit(str[i], pid);
		i++;
	}
	return (0);
}
