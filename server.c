/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:12:55 by slayer            #+#    #+#             */
/*   Updated: 2025/11/21 03:39:40 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	str_len(int *curr_bit_len, int *len, int sig, int client_pid)
{
	if (sig == SIGUSR2)
		*len |= (1 << *curr_bit_len);
	(*curr_bit_len)++;
	kill(client_pid, SIGUSR1);
}

static void	char_init(t_Message	*message, int sig, int client_pid)
{
	if (sig == SIGUSR2)
		message->str[message->pos] |= (1 << message->curr_bit_char);
	message->curr_bit_char++;
	if (message->curr_bit_char >= 8)
	{
		message->pos++;
		message->curr_bit_char = 0;
	}
	kill(client_pid, SIGUSR1);
}

static void	restart_vars(t_Message *message, int client_pid)
{
	if (message->str)
	{
		ft_putstr_fd(message->str, 1);
		ft_putstr_fd("\n", 1);
		free(message->str);
	}
	message->curr_bit_len = 0;
	message->curr_bit_char = 0;
	message->len = 0;
	message->pos = 0;
	message->str = 0;
	kill(client_pid, SIGUSR2);
}

static void	ft_signal(int sig, siginfo_t *info, void *context)
{
	static t_Message	message;

	(void)context;
	if (message.curr_bit_len < 32)
		return (str_len(&message.curr_bit_len,
				&message.len, sig, info->si_pid));
	if (!message.str)
		message.str = ft_calloc(sizeof(char), message.len + 1);
	char_init(&message, sig, info->si_pid);
	if (message.pos >= message.len)
		restart_vars(&message, info->si_pid);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("PID=", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sa.sa_sigaction = ft_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(WAIT_TIME);
	return (0);
}
