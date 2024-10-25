/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:59:51 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/25 09:14:37 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trim_line(char *line)
{
	unsigned int		len;
	unsigned int		i;
	char				*next_line;

	i = 0;
	len = ft_check_n(line);
	next_line = malloc((len + 1) * sizeof(char));
	if (!next_line)
		return (0);
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
	while (line[i] != '\n')
		i++;
	start = i;
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
	int				check;

	count = 1;
	check = 0;
	stock = malloc(1);
	if (!stock)
		return (0);
	while (count != 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		buf[count + 1] = '\0';
		check = ft_check_n(buf);
		if (check != -1)
		{
			tmp = ft_strjoin(stock, buf);
			stock = tmp;
			free(tmp);
		}
		else if (check == -1)
			break;
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*line;
	char			*next_line;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	if (fd > 1024)
		return (0);
	line = ft_find_line(buf, fd);
	free(buf);
	next_line = ft_trim_line(line);
	ft_rest_end(line);
	free(line);
	return (next_line);
}
