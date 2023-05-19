/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:06:00 by esafouan          #+#    #+#             */
/*   Updated: 2023/05/19 17:31:24 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*after_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	line = (char *)malloc(gnl_strlen(buffer) - i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (buffer[i] != '\0')
		line[j++] = buffer[++i];
	free(buffer);
	line[j] = '\0';
	return (line);
}

char	*first_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		line = (char *)malloc(sizeof(char) * (i + 1));
	else
		line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_buffer(int fd, char *buffer)
{
	char	*dst;
	int		result;

	if (!buffer)
		buffer = gnl_calloc(1, 1);
	dst = (char *)malloc(BUFFER_SIZE + 1);
	if (!dst)
		return (NULL);
	result = 1;
	while (!gnl_strchr(buffer, '\n') && result != 0)
	{
		result = read(fd, dst, BUFFER_SIZE);
		if (result == -1)
		{
			free(buffer);
			free(dst);
			return (NULL);
		}
		dst[result] = '\0';
		buffer = gnl_strjoin(buffer, dst);
	}
	free(dst);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = first_line(buffer);
	buffer = after_line(buffer);
	return (line);
}

void	checking(char *s, t_win *win, t_check *check)
{
	win->fd = open(s, O_RDWR);
	if (win->fd < 0)
		printferror("map not found");
	pars_map(win, check);
	last_map(win);
	calcul_x_y(win);
}
