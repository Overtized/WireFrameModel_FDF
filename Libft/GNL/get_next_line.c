/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:08:06 by mchanlia          #+#    #+#             */
/*   Updated: 2025/06/11 18:28:54 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*static_buff[MAX_FD];
	char		*line;

	if (fd == -42)
	{
		freeall(static_buff);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd >= MAX_FD)
		return (free(static_buff[fd]), static_buff[fd] = NULL, NULL);
	static_buff[fd] = read_store(fd, static_buff[fd]);
	if (!static_buff[fd])
		return (static_buff[fd] = NULL, NULL);
	line = extract_line(static_buff[fd]);
	if (!line)
		return (free(static_buff[fd]), static_buff[fd] = NULL, NULL);
	static_buff[fd] = clean_buff(static_buff[fd]);
	return (line);
}

char	*read_store(int fd, char *buff)
{
	char	*buffer;
	char	*temp_buff;
	int		byteread;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(buff), NULL);
	if (!buff)
		buff = ft_strdup("");
	if (!buff)
		return (free(buffer), NULL);
	byteread = 1;
	while (!ft_strchr(buff, '\n') && byteread > 0)
	{
		byteread = read(fd, buffer, BUFFER_SIZE);
		if (byteread < 0)
			return (free(buff), free(buffer), NULL);
		buffer[byteread] = '\0';
		temp_buff = ft_strjoin(buff, buffer);
		if (!temp_buff)
			return (free(buff), free(buffer), NULL);
		free(buff);
		buff = temp_buff;
	}
	return (free(buffer), buff);
}

char	*extract_line(char *buffer)
{
	size_t	i;

	i = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	return (ft_substr(buffer, 0, i));
}

char	*clean_buff(char *buffer)
{
	char	*newbuff;
	size_t	i;

	i = 0;
	while (buffer && buffer[i] && buffer[i] != '\n')
	{
		i++;
	}
	if (!buffer[i])
		return (free(buffer), NULL);
	if (buffer[i + 1] == '\0')
		return (free(buffer), NULL);
	newbuff = ft_strdup(buffer + i + 1);
	if (!newbuff)
		return (free(buffer), NULL);
	free(buffer);
	return (newbuff);
}

void	freeall(char **static_buff)
{
	int	i;

	i = 0;
	while (i < MAX_FD)
	{
		free(static_buff[i]);
		static_buff[i++] = NULL;
	}
}
