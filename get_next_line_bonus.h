/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:05:28 by ncharbog          #+#    #+#             */
/*   Updated: 2024/10/29 09:37:02 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_rest_end(char *buf);
char	*ft_strdup(char *s);
void	*ft_join_buf(char *buf, char *tmp, int count);
char	*ft_trim_line(char *buf);
int		ft_strlen(char *s);
int		ft_check_n(char *s);
void	*ft_free(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);

#endif