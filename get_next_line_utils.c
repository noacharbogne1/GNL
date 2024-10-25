/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:00:02 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/25 17:16:27 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*dest;
	size_t	n;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (size_t) - 1 / size)
		return (0);
	n = nmemb * size;
	dest = malloc(n * sizeof(char));
	if (dest == NULL)
		return (0);
	ft_memset(dest, 0, n);
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*adress;

	adress = (unsigned char *)s;
	while (n > 0)
	{
		*adress = c;
		adress++;
		n--;
	}
	return (s);
}

int	ft_strlen(char *s)
{
	unsigned int	i;

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

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int		i;
	unsigned int		j;
	char				*dest;

	i = 0;
	j = 0;
	dest = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (dest == NULL)
		return (0);
	while (*s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
