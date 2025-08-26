/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:12:52 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/26 18:53:50 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	check_hex_validity(char *buffer)
{
	char	*cursor;
	int		hex_len;
	char	*tmp;

	hex_len = 0;
	cursor = buffer;
	tmp = cursor;
	while (1)
	{
		hex_len = 0;
		cursor = (ft_strchr(cursor, 'x'));
		if (!cursor)
			break;
		if (cursor == buffer || *(cursor - 1) != '0')
			return (false);
		cursor++;
		while (hex_len < 6 && ft_ishex((int)cursor[hex_len]))
			hex_len++;
		if (hex_len == 1)
			return (false);
		if (cursor[hex_len] != '\0' && !ft_isspace((int)cursor[hex_len]))
			return (false);
		cursor+= hex_len;
	}
	return (true);
}

// static void	parse_token(char *line, t_map *map_params)
// {
// 	map_params->X_pos = ft_atoi_base(line, "0123456789ABCDEF");
// 	map_params->Y_pos = ft_atoi_base(line, "0123456789ABCDEF");
// 	map_params->Z_pos = ft_atoi_base(line, "0123456789ABCDEF");
// }

// static void	parse_row(char *line, t_map *map_params)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		parse_token(line, map_params);
// 		i++;
// 	}
// }

bool	parse_map(char *map, t_map **map_params)
{
// 	int		fd;
// 	char	*line;

	(void) map;
	(void) map_params;
	// a voir si tu peux pas juste parcourir la struct car tu as stocker la
	// map dedans donc tu pourrais juste get next line de la struct
	// fd = open(map, O_RDONLY);
	// if (fd == -1)
	// 	return(perror("open fail \n"), false);
	// line = get_next_line(fd);
	// while (line)
	// {
	// 	parse_row(line, map_params);
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
	// close(fd);
	return (true);
}
