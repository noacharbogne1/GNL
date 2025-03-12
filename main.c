/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:24:01 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/31 08:11:54 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/*void test_1char()
{
	printf("\e[1;36m-//One char by line\n\e[0m");
	int fd = open("./gnl_testfiles/1char", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			printf("%s", line);
	}
	if (fd != -1)
		close (fd);
}

void	testerfunction(void(*f)(void))
{
	static int	i = 0;
	i++;
	printf("\n\e[1;33m//-------------------\n");
	printf("\e[1;33mTest %d\e[0m\n", i);
	f();
	printf("\e[1;33m----ending test----//\e[0m\n\n");
}

int	main()
{
	testerfunction(test_1char);
}
*/
int	main()
{
	int 	fd;
	char	*a;

	fd = open("1char", O_RDONLY);
	a = get_next_line(fd);
	printf("%s", a);
	while (a != 0)
	{
		free(a);
		a = get_next_line(fd);
		if (a)
			printf("%s", a);
	}
	close (fd);
}
