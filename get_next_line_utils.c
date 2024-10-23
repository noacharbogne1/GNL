/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:00:02 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/23 11:07:45 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_copy(char *s)
{
	char	*dest;
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		s[i] = dest[i];
		i++;
	}
	return (dest)
}

int	ft_check_n(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *buf, static char *stock)
{
	int		i;
	int		len;

	i = 0;
	if (!buf)
		return (0);
	len = ft_strlen(stock);
	while (buf[i])
	{
		stock[len] = buf[i];
		len++;
		i++;
	}
	return (stock);
}