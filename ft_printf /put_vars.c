/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:15:35 by rucosta           #+#    #+#             */
/*   Updated: 2025/06/10 19:23:17 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	put_pointer(void *ptr)
{
	uintptr_t	address;
	char		buf[16];
	int			i;
	int			size;
	char		*base;

	address = (uintptr_t)ptr;
	if (address == 0)
		return (ft_putstr("(nil)"));
	i = 0;
	base = "0123456789abcdef";
	while (address)
	{
		buf[i++] = base[address % 16];
		address /= 16;
	}
	size = i;
	ft_putstr("0x");
	while (i--)
		ft_putchar(buf[i]);
	return (size + 2);
}

int	put_hex(unsigned int n, int uppercase)
{
	char	*base;
	char	buf[8];
	int		i;
	int		size;

	i = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n == 0)
		return (ft_putchar('0'));
	while (n)
	{
		buf[i++] = base[n % 16];
		n /= 16;
	}
	size = i;
	while (i--)
		ft_putchar(buf[i]);
	return (size);
}

int	put_unsigned(unsigned int n)
{
	char	buf[10];
	int		i;
	int		size;

	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (n)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}
	size = i;
	while (i--)
		ft_putchar(buf[i]);
	return (size);
}

int	put_int(int n)
{
	if (n < 0)
		return (ft_putchar('-') + put_unsigned(-n));
	return (put_unsigned(n));
}
