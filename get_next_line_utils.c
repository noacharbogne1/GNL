/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:00:02 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/24 11:06:49 by ncharbog         ###   ########.fr       */
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

int	ft_check_n(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		start;

	i = 0;
	if (!s2)
		return (0);
	start = ft_strlen(s1);
	while (s1[i])
	{
		s1[start] = s2[i];
		start++;
		i++;
	}
	return (s1);
}