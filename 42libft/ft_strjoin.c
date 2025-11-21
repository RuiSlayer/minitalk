/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:22:28 by rucosta           #+#    #+#             */
/*   Updated: 2025/04/29 13:54:06 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	join(char *ptr, char const *s, int i)
{
	int	j;

	j = 0;
	while (s[j] != '\0')
	{
		ptr[i] = s[j];
		i++;
		j++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	i = join(ptr, s1, i);
	i = join(ptr, s2, i);
	ptr[i] = '\0';
	return (ptr);
}
