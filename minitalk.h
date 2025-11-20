/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:41:07 by rucosta           #+#    #+#             */
/*   Updated: 2025/11/20 20:05:43 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
# define WAIT_TIME 700

typedef struct Message
{
	int	curr_bit_len;
	int	curr_bit_char;
	int	len;
	int	pos;
	char		*str;
}	t_Message;

