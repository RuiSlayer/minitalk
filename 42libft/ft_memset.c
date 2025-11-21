/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:48:14 by rucosta           #+#    #+#             */
/*   Updated: 2025/04/29 15:01:20 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;

	p = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n != 0)
	{
		*p++ = ch;
		n--;
	}
	return (s);
}

/* void print_memory(const unsigned char *s, size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%02x ", s[i]);
    printf("\n");
}
 */