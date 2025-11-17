/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slayer <slayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:06:07 by slayer            #+#    #+#             */
/*   Updated: 2025/11/17 23:27:50 by slayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_strlen(const char *c)
{
	int	len;

	len = 0;
	while (c[len] != '\0')
	{
		len++;
	}
	return (len);
}

static void	copy_str(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

static void	build_proc_path(char *buf, char *pid)
{
	copy_str(buf, "/proc/");
	copy_str(buf + 6, pid);
	copy_str(buf + 6 + ft_strlen(pid), "/fd/0");
}

static int	open_proc_fd(char *pid)
{
	char	path[64];

	build_proc_path(path, pid);
	return (open(path, O_WRONLY));
}

static void	send_string(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
}
static int	pid_parser(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
static int	string_parser(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!(argv[i] >= 32 && argv[i] <= 126))
			return (1);
		i++;
	}
	return (0);
}
int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 3)
		return (write(2, "Usage: ./client <pid> <string>\n", 32), 1);
	if (pid_parser(argv[1]))
		return (write(2, "<pid> must be all numerical and positive\n", 42), 1);
	fd = open_proc_fd(argv[1]);
	if (fd < 0)
		return (write(2, "file opening fail\n", 19), 1);
	if (string_parser(argv[2]))
		return (write(2, "<string> all caracters must be printable\n", 42), 1);
	send_string(fd, argv[2]);
	close(fd);
	return (0);
}

