/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:48:36 by rucosta           #+#    #+#             */
/*   Updated: 2025/04/22 01:03:43 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	j = 0;
	src_len = ft_strlen(src);
	while (dst[i] != '\0' && i < size)
		i++;
	dst_len = i;
	if (size <= dst_len)
	{
		return (size + src_len);
	}
	while (src[j] != '\0' && dst_len + j < size - 1)
	{
		dst[dst_len + j] = src[j];
		i++;
		j++;
	}
	dst[dst_len + j] = '\0';
	return (dst_len + src_len);
}

/* int main()
{
	char dst[20] = "Hello, ";
    const char *src = "World!";

    size_t result = ft_strlcat(dst, src, sizeof(dst));

    printf("Concatenated string: %s\n", dst);
    printf("Length of the string it tried to create: %zu\n", result);

    return 0;
} */