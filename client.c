/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slayer <slayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:06:07 by slayer            #+#    #+#             */
/*   Updated: 2025/11/19 23:12:51 by slayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
# define WAIT_TIME 700

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

/* static void	ft_signal(int sig)
{
	static int	bit;
	static int	byte;

	(void)sig;
	if (sig == SIGUSR2)
	{
		bit++;
		if (bit == 8)
		{
			byte++;
			bit = 0;
		}
	}
	else if (sig == SIGUSR1)
	{
		printf("\nBytes received with success: %d\n", byte + 1);
		exit(0);
	}
} */

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

static int	string_parser(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!(argv[i] >= 32 && argv[i] <= 126))
			return (1);
		i++;
	}
	return (0);
}

static void	ft_s_strlen_bit_bit(int len, int pid)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
	}
}

static void	send_nextchar_bit_bit(unsigned char len, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
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
	if (string_parser(argv[2]))
		return (write(2, "<string> all caracters must be printable\n", 42), -1);
	len = ft_strlen(argv[2]);
	pid = atoi(argv[1]);
	ft_s_strlen_bit_bit((len), pid);
	str = argv[2];
	i = -1;
	while (str[++i])
		send_nextchar_bit_bit(str[++i], pid);
	send_nextchar_bit_bit(str[++i], pid);
	return (0);
}
