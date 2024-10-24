/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:00:20 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/24 11:04:15 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_rest_end(char *str);
char	*ft_trim_line(char *str, char *dest);
int		ft_strlen(char *s);
int		ft_check_n(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif