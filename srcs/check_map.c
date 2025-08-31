/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:34:23 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/31 14:03:58 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static bool	check_hex_comb(char *buffer)
{
	char	*cursor;
	int		hex_len;

	cursor = buffer;
	while (cursor)
	{
		hex_len = 0;
		cursor = (ft_strchr(cursor, 'x'));
		if (!cursor)
			break ;
		if (cursor == buffer || *(cursor - 1) != '0')
			return ( false);
		cursor++;
		while (hex_len < 6 && ft_ishex((int)cursor[hex_len]))
			hex_len++;
		if (hex_len < 1)
			return (false);
		if (cursor[hex_len] != '\0' && !ft_isspace((int)cursor[hex_len]))
			return (false);
		cursor+= hex_len;
	}
	return ( true);
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
	int	hex_char;

	i = 0;
	hex_flag = 0;
	hex_char = 0;
	while (buffer[i])
	{
		if (!ft_isdigit_space(buffer[i]) && !ft_ishex(buffer[i]))
			return (false);
		if ((buffer[i] >= 'A' && buffer[i] <= 'F') || (buffer[i] >= 'a' && buffer[i] <= 'f'))
			hex_char = 1;
		if (buffer[i] == '0' && buffer[i + 1] == 'x')
			hex_flag = 1;
		i++;
	}
	if (hex_flag == 1)
	{
		if (!check_hex_comb(buffer))
			return (false);
	}
	else if (hex_flag == 0 && hex_char == 1)
		return (false);
	return (true);
}

static bool	test_map(char *map, t_map *map_strct)
{
	int		fd;
	char	*buffer;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (perror("open fail \n"), false);
	buffer = read_map(fd);
	if (!buffer)
		return (free(buffer), false);
	map_strct->map = ft_strdup(buffer);
	free(buffer);
	if (!test_map_validity(map_strct->map))
		return (free(map_strct->map), false);
	if (!test_int(map_strct->map))
		return (free(map_strct->map), false);
	return (close(fd), true);
}

bool	test_input(char *map, t_map *map_strct)
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
	if (!test_map(map, map_strct))
		return (false);
	return (true);
}
