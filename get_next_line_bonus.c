/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:05:14 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/29 14:35:17 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_trim_line(char *buf)
{
	int		len;
	int		i;
	char	*next_line;

	len = 0;
	while (buf[len] && buf[len] != '\n')
		len++;
	if (len == 0 && buf[0] != '\n')
		return (0);
	next_line = malloc((len + 2) * sizeof(char));
	if (!next_line)
		return (0);
	i = -1;
	while (i++ < len)
		next_line[i] = buf[i];
	if (buf[len] && buf[len] == '\n')
		next_line[i] = '\0';
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
		return (ft_free(buf, 0));
	start = i + 1;
	i = 0;
	rest = malloc((ft_strlen(buf) - start + 1) * sizeof(char));
	if (!rest)
		return (0);
	while (buf[start + i])
	{
		rest[i] = buf[start + i];
		i++;
	}
	rest[i] = '\0';
	free(buf);
	return (rest);
}

void	*ft_join_buf(char *buf, char *tmp, int count)
{
	char	*stock;

	stock = NULL;
	tmp[count] = '\0';
	stock = ft_strjoin(buf, tmp);
	if (!stock)
		return (ft_free(buf, tmp));
	free(buf);
	buf = stock;
	return ((char *)buf);
}

char	*ft_find_line(char *buf, int fd)
{
	char			*tmp;
	int				count;

	count = 0;
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (0);
	while (1)
	{
		count = read(fd, tmp, BUFFER_SIZE);
		if (count == -1)
			return (ft_free(tmp, buf));
		if (count == 0)
		{
			ft_free(tmp, 0);
			break ;
		}
		buf = ft_join_buf(buf, tmp, count);
		if (ft_check_n(buf))
			break ;
	}
	if (count != 0)
		free(tmp);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char		*buf[1024];
	char			*next_line;

	if (fd >= 1024 || fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf[fd] = ft_find_line(buf[fd], fd);
	if (!buf[fd])
		return (ft_free(buf[fd], 0));
	next_line = ft_trim_line(buf[fd]);
	if (!next_line)
		return (ft_free(buf[fd], 0));
	buf[fd] = ft_rest_end(buf[fd]);
	return (next_line);
}