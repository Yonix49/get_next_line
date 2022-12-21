/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:09:58 by mhajji-b          #+#    #+#             */
/*   Updated: 2022/12/21 15:37:14 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000000
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(char *src);
size_t	ft_verification(int start, size_t len, char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_scotch(char *dest, char *ss1, char *ss2);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif