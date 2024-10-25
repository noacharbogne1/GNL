/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:59:51 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/25 17:32:35 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trim_line(char *buf)
{
	int		len;
	int		i;
	char	*next_line;

	len = 0;
	while (buf[len] && buf[len] != '\n')
		len++;
	if (len == 0 || len > ft_strlen(buf))
		return (0);
	next_line = malloc(((buf[len] == '\n') + len + 1) * sizeof(char));
	if (!next_line)
		return (0);
	i = 0;
	while (i < len)
	{
		next_line[i] = buf[i];
		i++;
	}
	if (buf[len] && buf[len] == '\n')
	{
		next_line[i] = '\n';
		next_line[i + 1] = '\0';
	}
	else
		next_line[i] = '\0';
	return (next_line);
}

char	*ft_rest_end(char *buf)
{
	char			*rest;
	unsigned int	i;
	unsigned int	start;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] != '\n')
	{
		free(buf);
		return (0);
	}
	start = i + 1;
	i = 0;
	rest = malloc(((ft_strlen(buf) - 1) - start + 1) * sizeof(char));
	if (!rest)
		return (0);
	while(buf[start + i])
	{
		rest[i] = buf[start + i];
		i++;
	}
	rest[i] = '\0';
	free(buf);
	return (rest);
}

char	*ft_find_line(char *buf, int fd)
{
	char			*stock;
	char			*tmp;
	unsigned int	count;

	count = 0;
	if (!buf)
	{
		buf = malloc(1);
		buf[0] = '\0';
	}
	tmp = calloc((BUFFER_SIZE + 1), 1);
	if (!tmp)
		return (0);
	while (1)
	{
		count = read(fd, tmp, BUFFER_SIZE);
		tmp[count] = '\0';
		stock = ft_strjoin(buf, tmp);
		free(buf);
		buf = stock;
		if (ft_check_n(buf) || count == 0)
			break ;
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char		*buf;
	char			*next_line;

	if (fd > 1024 || fd < 0)
		return (0);
	buf = ft_find_line(buf, fd);
	next_line = ft_trim_line(buf);
	buf = ft_rest_end(buf);
	return (next_line);
}
