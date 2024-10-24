/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:24:01 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/24 11:13:20 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main()
{
	int 	fd;
	char	*a;

	fd = open("test", O_RDONLY);
	a = get_next_line(fd);
	printf("%s", a);
	free(a);
}