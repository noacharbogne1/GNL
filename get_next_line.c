/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:59:51 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/24 17:02:25 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trim_line(char *str, char *dest)
{
	int		len;
	int		i;

	i = 0;
	while(str[i] != '\n')
		i++;
	len = i;
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_rest_end(char *str)
{
	static char			*rest;
	unsigned int		i;
	unsigned int		start;
	unsigned int		end;

	i = 0;
	while (str[i] != '\n')
		i++;
	start = i;
	end = ft_strlen(str) - 1;
	i = 0;
	rest = malloc((end - start + 1) * sizeof(char));
	while(str[start])
	{
		rest[i] = str[start];
		i++;
		start++;
	}
	rest[i] = '\0';
	free(str);
	return (rest);
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*tmp;
	char			*stock;
	unsigned int	count;
	int				check;

	check = 0;
	count = 1;
	tmp = "";
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	while (count != 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE + 1] = '\0';
		check = ft_check_n(buf);
		if (check >= 0)
		{
			stock = malloc((ft_strlen(tmp) + check + 1) * sizeof(char));
			if (!stock)
				return (0);
			stock = ft_trim_line(buf, stock);
			ft_rest_end(buf);
		}
		if (check == -1)
		{
			stock = malloc((ft_strlen(tmp) + count + 1) * sizeof(char));
			if (!stock)
				return (0);
			stock = ft_strjoin(tmp, buf);
			tmp = stock;
			free(stock);
		}
		if (check = '\n')
			break;
	}
	free(buf);
	return (tmp);
}
