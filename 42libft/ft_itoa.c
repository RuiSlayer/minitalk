/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruislayer <ruislayer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:27:29 by rucosta           #+#    #+#             */
/*   Updated: 2025/04/30 19:44:36 by ruislayer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	get_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	long	nb;

	nb = n;
	len = get_len(n);
	if (nb < 0)
		nb = -nb;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len > 0)
	{
		len--;
		res[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
/* void	print_test(long n)
{
	char	*result;

	result = ft_itoa(n);
	if (result == NULL)
	{
		printf("ft_itoa(%ld): NULL (allocation failed)\n", n);
		return ;
	}
	printf("ft_itoa(%ld) = \"%s\"\n", n, result);
	free(result);
}

int	main(void)
{
	print_test(0);
	print_test(42);
	print_test(-42);
	print_test(1234567890);
	print_test(-1234567890);
	print_test(2147483647);
	print_test(-2147483648);
	print_test(9223372036854775807);
	print_test(-9223372036854775807 - 1);
	return (0);
} */