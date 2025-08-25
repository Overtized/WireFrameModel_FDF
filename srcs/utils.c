/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:34:23 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/25 17:39:58 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char *read_map(int fd)
{
	char *buffer;
	char *line;
	char *join;

	buffer = ft_strdup("");
	if (!buffer)
		return(NULL);
	line = get_next_line(fd);
	if (!line)
		return(NULL);
	while (line)
	{
		join = ft_strjoin(buffer, line);
		if (!join)
			return(NULL);
		free (line);
		free (buffer);
		buffer = join;
		line = get_next_line(fd);
	}
	return (join);
}
static bool	test_map_validity(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		printf("buf[%d] = '%c' (%d)\n", i, buffer[i], (unsigned char)buffer[i]);
		if (!ft_isdigit_space((unsigned char)buffer[i]))
			return( printf("buf[%d] = %d\n", i, (unsigned char)buffer[i]), false);
		i++;
	}
	return (true);
}

static bool	test_map(char *map)
{
	int	fd;
	char *buffer;
	t_map	map_s;


	fd = open(map, O_RDONLY);
	if (fd == -1)
		return(perror("open fail \n"), false);
	buffer = read_map(fd);
	if (!buffer)
		return (false);
	close (fd);
	if (!test_map_validity(buffer))
		return (false);
	map_s.map = buffer;
	free (buffer);
	return (true);
}

bool	test_input(char *map)
{
	char *cursor;
	char *extension = ".fdf";

	cursor = 0;
	if (!map)
		return(false);
	cursor = ft_strrchr(map, '.');
	if (!cursor)
		return(false);
	if (ft_strcmp(cursor, extension) != 0)
		return (false);
	if (!test_map(map))
		return(false);
	return (true);
}
// tester les qrgs, tester l'extension du fichier, tester la validite de la map\
	// tester la presence de chiffre