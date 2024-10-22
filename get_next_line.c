/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:59:51 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/22 16:31:16 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buf;
	char			*next_line;
	unsigned int	count;
	unsigned int	i;

	i = 0;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	while (buf[i] != '\n')
	{
		count = read(fd, buf, BUFFER_SIZE);
		while (i < count)
		{
			if (buf[i] == '\n')
				return (ft_strcpy(buf));
			i++;
		}
		i = 0;
		strjoin(static, buf);
	}
	free(buf);
	return (next_line);
}