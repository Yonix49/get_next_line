/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:19:00 by mhajji-b          #+#    #+#             */
/*   Updated: 2022/12/21 15:38:44 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int	is_char_set(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*retrieve_file_content(int fd, char *buf, char *reste)
{
	int		read_ptr;
	char	*temp;

	temp = NULL;
	read_ptr = 1;
	if (reste && is_char_set(reste, 10) == 1)
		return (reste);
	while (read_ptr != '\0')
	{
		read_ptr = read(fd, buf, BUFFER_SIZE);
		if (read_ptr == -1)
			return (0);
		else if (read_ptr == 0)
			break ;
		buf[read_ptr] = '\0';
		temp = reste;
		reste = ft_strjoin(temp, buf);
		free(temp);
		if (is_char_set(reste, 10) == 1)
			break ;
	}
	return (reste);
}

static char	*extract_line(char *line)
{
	int		i;
	char	*reste;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (0);
	reste = ft_substr(line, i + 1, ft_strlen(line) - i);
	line[i + 1] = '\0';
	if (*reste == '\0')
	{
		free(reste);
		reste = NULL;
	}
	return (reste);
}

char	*get_next_line(int fd)
{
	static char	*reste;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = retrieve_file_content(fd, buf, reste);
	free(buf);
	if (!line)
		return (NULL);
	reste = extract_line(line);
	return (line);
}

// int	main(void)
// {
// 	int fd;

// 	char *line;

// 	fd = open("/mnt/nfs/homes/mhajji-b/get_next_line/bible.txt",
// 				O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		printf("---- > %s\n", line);
// 		if (line == NULL)
// 			break ;
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }