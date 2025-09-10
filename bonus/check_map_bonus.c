/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:34:23 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/10 12:12:59 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf_bonus.h"

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
			return (false);
		cursor++;
		while (hex_len < 6 && ft_ishex((int)cursor[hex_len]))
			hex_len++;
		if (hex_len < 1)
			return (false);
		if (cursor[hex_len] != '\0' && !ft_isspace((int)cursor[hex_len]))
			return (false);
		cursor += hex_len;
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

static bool	test_map_validity(char *buf)
{
	int	i;
	int	hex_flag;
	int	hex_char;

	i = 0;
	hex_flag = 0;
	hex_char = 0;
	if (!buf)
		return (false);
	while (buf[i])
	{
		if (!ft_isdigit_space(buf[i]) && !ft_ishex(buf[i]))
			return (false);
		if ((buf[i] >= 65 && buf[i] <= 70) || (buf[i] >= 97 && buf[i] <= 102))
			hex_char = 1;
		if (buf[i] == '0' && buf[i + 1] == 'x')
			hex_flag = 1;
		i++;
	}
	if (hex_flag == 1 && !check_hex_comb(buf))
		return (false);
	if (hex_flag == 0 && hex_char == 1)
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
		return (false);
	if (!test_int(map_strct->map))
		return (false);
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
