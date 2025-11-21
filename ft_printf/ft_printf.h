/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:28:15 by rucosta           #+#    #+#             */
/*   Updated: 2025/06/10 19:24:04 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

int			ft_putchar(char c);
int			ft_putstr(char *s);
int			put_pointer(void *ptr);
int			put_hex(unsigned int n, int uppercase);
int			put_unsigned(unsigned int n);
int			put_int(int n);
int			ft_printf(const char *ptr, ...);
#endif