/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:59:51 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/23 11:31:21 by ncharbog         ###   ########.fr       */
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
	return (dest); // attention il manque un free !
}

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*stock;
	unsigned int	count;
	unsigned int	check;
	unsigned int	i;

	check = 0;
	i = 0;
	count = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	stock = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!stock)
		return (0);
	while (stock[i])
	{
		stock[i] = '\0';
		i++;
	}
	while (check == 0 && count > 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE + 1] = '\0';
		stock = ft_strjoin(buf, stock);
		check = ft_check_n(stock);
		if (check == 0)
			ft_stock_free(stock);
	}
	free(buf);
	return (ft_trim_line(stock));
}
