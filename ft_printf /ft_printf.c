/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:38:36 by rucosta           #+#    #+#             */
/*   Updated: 2025/06/10 19:23:34 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	print_var(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (put_pointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (put_int(va_arg(args, int)));
	else if (c == 'u')
		return (put_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (put_hex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (put_hex(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += print_var(format[i + 1], args);
			i += 2;
			continue ;
		}
		count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/* int main()
{
	int x = 10;
	int *ptr = &x;
	char *str = NULL;
	int a = ft_printf(NULL);

	
	ft_printf("ft_printf:%c", 'a');
    printf("\n");
	printf("printf %c", 'a');
	printf("\n");
    ft_printf("ft_printf:%s", "ola");
    printf("\n");
	printf("printf %s", "ola");
	printf("\n");
    ft_printf("ft_printf:%d", -123);
    printf("\n");
	printf("printf %d", -123);
	printf("\n");
    ft_printf("ft_printf:%i", 123);
    printf("\n");
	printf("printf %i",123);
	printf("\n");
    ft_printf("ft_printf:%u", -1);
	printf("\n");
	printf("printf %u", -1);
    printf("\n");
    ft_printf("ft_printf: %x", 255);
    printf("\n");
	printf("printf : %x", 255);
	printf("\n");
    ft_printf("ft_printf:%X", 255);
    printf("\n");
	printf("printf:%X", 255);
	printf("\n");
    ft_printf("ft_printf:%%");
    printf("\n");
	printf("printf %%");
	printf("\n");
	printf("pritnf:%p", ptr);
	printf("\n");
	ft_printf("ft_pritnf:%p", ptr);
	printf("\n");
	printf("printf%s", str);
	printf("\n");
	ft_printf("ft_printf:%s", str);
	printf("\n");
    ft_printf("ft_print ptr = %p", NULL);
    printf("\n");
    printf(" printf ptr =  %p", NULL);
    printf("\n");
	ft_printf("%d", a);
    return 0;
} */
