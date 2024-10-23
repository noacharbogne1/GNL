/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:59:51 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/23 16:24:14 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trim_line(static char *stock)
{
	char	*dest;
	int		len;
	int		end;
	int		i;

	i = 0;
	while(stock[i] != '\n')
		i++;
	len = i;
	i = 0;
	dest = malloc ((len + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (i < len)
	{
		dest[i] = stock[i];
		i++;
	}
	dest[i] = '\0';
	return (dest); // attention il manque un free !!!!
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
	while(str[i])
		i++;
	end = i;
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
	static char		*stock;
	char			*next_line;
	unsigned int	count;
	unsigned int	check;

	check = 0;
	count = 0;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	count = read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE + 1] = '\0';
	if (count == 0)
	{
		check = ft_check_n(buf);
		if (check < ft_strlen(buf))
			ft_rest_end(buf);
		return (ft_copy(buf, check));
	}
	while (check == 0 && count > 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE + 1] = '\0';
		stock = malloc((count + 1) * sizeof(char));
		if (!stock)
			return (0);
		stock = ft_strjoin(buf, stock);
		check = ft_check_n(stock);
		if (check == 0)
			ft_rest(stock);
	}
	free(buf);
	return (ft_trim_line(stock));
}
