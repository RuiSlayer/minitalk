/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slayer <slayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:12:55 by slayer            #+#    #+#             */
/*   Updated: 2025/11/17 23:32:46 by slayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


int	main(void)
{
	char	buf[1024];
	ssize_t	nbytes;
	printf("PID=%d\n", getpid());
	while (1)
	{
		nbytes = read(0, buf, sizeof(buf) - 1);
		if (nbytes > 0)
		{
			buf[nbytes] = '\0';
			write(1, "Received: ", 10);
			write(1, buf, nbytes);
		}
		else if (nbytes == 0)
			break;
		else
			printf("read");
	}
	return (0);
}

