/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:34:23 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/26 18:53:53 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static bool	check_hex_comb(char *buffer)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '0' && buffer[i + 1] == 'x')
			flag = 1;
		i++;
	}
	if (flag == 0)
		return (false);
	else
	{
		if (!check_hex_validity(buffer))
			return (false);
	}
	return (true);
}

static char	*read_map(int fd)
{
	char	*buffer;
	char	*line;
	char	*join;

	buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (free(buffer), NULL);
	while (line)
	{
		join = ft_strjoin(buffer, line);
		if (!join)
			return (NULL);
		free(line);
		free(buffer);
		buffer = join;
		line = get_next_line(fd);
	}
	return (join);
}

static bool	test_map_validity(char *buffer)
{
	int	i;
	int	hex_flag;

	i = 0;
	hex_flag = 0;
	while (buffer[i])
	{
		if (!(ft_isdigit_space(buffer[i]) || ft_ishex(buffer[i])))
			return (false);
		if (buffer[i] == '0' && buffer[i + 1] == 'x')
			hex_flag = 1;
		i++;
	}
	if (hex_flag == 1)
	{
		if (!check_hex_comb(buffer))
			return (false);
	}
	return (true);
}

static bool	test_map(char *map, t_map *map_cf)
{
	int		fd;
	char	*buffer;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (perror("open fail \n"), false);
	buffer = read_map(fd);
	if (!buffer)
		return (free(buffer), false);
	close(fd);
	if (!test_map_validity(buffer))
		return (free(buffer), false);
	map_cf->map = buffer;
	return (true);
}

bool	test_input(char *map, t_map *map_cf)
{
	char	*cursor;
	char	*extension;

	extension = ".fdf";
	cursor = 0;
	if (!map)
		return (false);
	cursor = ft_strrchr(map, '.');
	if (!cursor)
		return (false);
	if (ft_strcmp(cursor, extension) != 0)
		return (false);
	if (!test_map(map, map_cf))
		return (false);
	return (true);
}

// tester les qrgs, tester l'extension du fichier, tester la validite de la map\
	// tester la presence de chiffre