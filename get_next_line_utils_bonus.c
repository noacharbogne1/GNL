/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:05:00 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/29 14:38:16 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_free(char *s1, char *s2)
{
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_check_n(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *buf, char *tmp)
{
	unsigned int		i;
	unsigned int		j;
	char				*dest;

	i = 0;
	j = 0;
	if (!buf && !tmp)
		return (0);
	dest = malloc((ft_strlen(buf) + ft_strlen(tmp) + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (buf && buf[i])
	{
		dest[i] = buf[i];
		i++;
	}
	j = 0;
	while (tmp && tmp[j])
	{
		dest[i] = tmp[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
