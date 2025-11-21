/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:12:55 by slayer            #+#    #+#             */
/*   Updated: 2025/11/21 02:31:18 by rucosta          ###   ########.fr       */
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

static void	char_init(int *curr_bit_char, int *pos, int sig, char *str, int client_pid)
{
	if (sig == SIGUSR2)
		str[*pos] |= (1 << *curr_bit_char);
	(*curr_bit_char)++;
	if (*curr_bit_char >= 8)
	{
		(*pos)++;
		*curr_bit_char = 0;
	}
	kill(client_pid, SIGUSR1);
}

static void	restart_vars(t_Message *message, int client_pid)
{
	if (message->str)
	{
		printf("%s\n", message->str);
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
	static t_Message message;

	(void)context;
	if(message.curr_bit_len < 32)
		return (str_len(&message.curr_bit_len, &message.len, sig, info->si_pid));
	if(!message.str)
		message.str = calloc(sizeof(char), message.len + 1);
	char_init(&message.curr_bit_char, &message.pos, sig, message.str, info->si_pid);
	if (message.pos >= message.len)
		restart_vars(&message, info->si_pid);
}

int	main(void)
{
	struct sigaction	sa;

	printf("PID=%d\n", getpid());
	sa.sa_sigaction = ft_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(WAIT_TIME);
	return (0);
}
