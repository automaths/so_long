/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:50:44 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/20 21:43:56 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_fd(int fd, char *buffer)
{
	char	*tmp;
	int		size;

	tmp = (char *)malloc(sizeof(char) * (4096 + 1));
	if (tmp == NULL)
		return (NULL);
	size = 1;
	while (ft_strchr_gnl(buffer) == NULL && size != 0)
	{
		size = read(fd, tmp, 4096);
		if (size < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[size] = '\0';
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*get_the_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_buffer(char *buffer)
{
	int		n;
	int		m;
	int		i;
	char	*new_buffer;

	n = 0;
	m = ft_strlen(buffer);
	while (buffer[n] && buffer[n] != '\n')
		n++;
	if (buffer[n] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(sizeof(char) * (m - n + 1));
	if (new_buffer == NULL)
		return (NULL);
	i = 0;
	while (buffer[n++])
		new_buffer[i++] = buffer[n];
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0)
		return (NULL);
	buffer = read_fd(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = get_the_line(buffer);
	buffer = new_buffer(buffer);
	return (line);
}
