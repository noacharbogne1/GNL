/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:59:51 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/24 10:01:58 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trim_line(char *str)
{
	char	*dest;
	int		len;
	int		end;
	int		i;

	i = 0;
	while(str[i] != '\n')
		i++;
	len = i;
	i = 0;
	dest = malloc ((len + 1) * sizeof(char));
	if (!dest)
		return (0);
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
	static char			*stock;
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
		stock[i] = str[start];
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
	char			*next_line;
	static char		*stock;
	unsigned int	count;
	unsigned int	check;

	check = 0;
	count = 0;
	*stock = "";
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	while (check == -1 && count > 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE + 1] = '\0';
		check = ft_check_n(buf);
		if (check >= 0)
		{
			next_line = malloc((check + 1) * sizeof(char));
			if (!next_line)
				return (0);
			next_line = ft_trim_line(next_line, buf);
			ft_rest_end(buf);
		}
		while (check == -1)
		{
			stock = malloc((ft_strlen(stock) + count + 1) * sizeof(char));
			if (!stock)
				return (0);
			// free(stock);
			stock = ft_strjoin(stock, buf);
			count = read(fd, buf, BUFFER_SIZE);
			buf[BUFFER_SIZE + 1] = '\0';
			check = ft_check_n(buf);
		}

	}
	free(buf);
	return (next_line);
}
