/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:12:55 by slayer            #+#    #+#             */
/*   Updated: 2025/11/20 20:21:03 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    disp(int sig)
{
    static char tracker;
    printf("%d", (sig));
    if (tracker++ / 7)
    {
        tracker = 0;
        printf("|");
    }
}

static void	str_len(int *curr_bit_len, int *len, int sig)
{
	if (sig == SIGUSR2)
	{
		disp(1);
		*len |= (1 << *curr_bit_len);
	}
	else
		disp(0);
	(*curr_bit_len)++;
	if (*curr_bit_len == 32)
	{
		(printf("\nbit_len= %d\n",*len));
		return ;
	}
}

static void	char_init(int *curr_bit_char, int *pos, int sig, char *str)
{
	if (sig == SIGUSR2)
	{
		disp(1);
		str[*pos] |= (1 << *curr_bit_char);
	}
	else
		disp(0);
	(*curr_bit_char)++;
	if (*curr_bit_char >= 8)
	{
		(printf("\n%d: char= %c\n",*pos, str[*pos]));
		(*pos)++;
		*curr_bit_char = 0;
	}
}

static void	restart_vars(t_Message *message)
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
}

static void	ft_signal(int sig)
{
	static t_Message message;

	if(message.curr_bit_len < 32)
		return (str_len(&message.curr_bit_len, &message.len, sig));
	if(!message.str)
		message.str = calloc(sizeof(char), message.len + 1);
	char_init(&message.curr_bit_char, &message.pos, sig, message.str);
	if (message.pos >= message.len)
		restart_vars(&message);
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
