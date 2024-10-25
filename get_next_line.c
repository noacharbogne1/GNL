/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:59:51 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/25 11:34:47 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trim_line(char *line)
{
	int		len;
	int		i;
	char	*next_line;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	len = i + 1;
	if (len == 0 || len > ft_strlen(line))
		return (0);
	next_line = malloc((len + 1) * sizeof(char));
	if (!next_line)
		return (0);
	i = 0;
	while (i < len)
	{
		next_line[i] = line[i];
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

char	*ft_rest_end(char *line)
{
	static char			*rest;
	unsigned int		i;
	unsigned int		start;
	unsigned int		end;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] != '\n')
	{
		free(line);
		return (0);
	}
	start = i + 1;
	end = ft_strlen(line) - 1;
	i = 0;
	rest = malloc((end - start + 1) * sizeof(char));
	if (!rest)
		return (0);
	while(line[start])
	{
		rest[i] = line[start];
		i++;
		start++;
	}
	rest[i] = '\0';
	free(line);
	return (rest);
}

char	*ft_find_line(char *buf, int fd)
{
	char			*stock;
	char			*tmp;
	unsigned int	count;

	count = 1;
	stock = malloc(1);
	if (!stock)
		return (0);
	stock[0] = '\0';
	while (count != 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		buf[count] = '\0';
		if (!ft_check_n(buf))
		{
			tmp = ft_strjoin(stock, buf);
			free(stock);
			stock = tmp;
		}
		else if (ft_check_n(buf))
		{
			tmp = ft_strjoin(stock, buf);
			free(stock);
			stock = tmp;
			break ;
		}
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*line;
	char			*next_line;

	if (fd > 1024 || fd < 0)
		return (0);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	memset(buf, 0, (BUFFER_SIZE + 1));
	line = ft_find_line(buf, fd);
	free(buf);
	next_line = ft_trim_line(line);
	ft_rest_end(line);
	return (next_line);
}
