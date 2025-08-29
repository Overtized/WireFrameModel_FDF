/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:12:52 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/29 11:21:59 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_token_number(char *line)
{
	int	i;
	char **split;
	int	token;
	size_t	len;
	char *comma;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	token = 0;
	i = 0;
	split = ft_split(line, ' ');
	if(!split)
		return (ft_free_double_char(split), -1);
	while (split[i])
	{
		comma = strchr(split[i], ',');
		if (comma)
			*comma = '\0';
		token ++;
		i++;
	}
	ft_free_double_char(split);
	return(token);
}
t_points	**allocate_map(t_map *map, t_points **map_point)
{
	int	i;

	i = 0;
	map_point = malloc(sizeof(t_points *) * map->rows);
	if (!map_point)
		return (NULL);
	while (i < map->rows)
	{
		map_point[i] = malloc(sizeof(t_points) * map->token_per_lines);
		if (!map_point[i])
		{
			while (i > 0)
			{
				free(map_point[i]);
				free(map_point);
				i--;
				return (NULL);
			}
		}
		i++;
	}
	return(map_point);
}
bool	init_map(char *raw_map, t_map *map_config)
{
	int	fd;
	char *line;
	int	line_tok_count;

	line_tok_count = 0;
	fd = open(raw_map, O_RDONLY);
	if (fd == -1)
		return (perror("open failed\n"), false);
	line = get_next_line(fd);
	while (line)
	{
		line_tok_count = get_token_number(line);
		if (line_tok_count == -1)
			return (close(fd), false);
		if (map_config->token_per_lines == 0)
			map_config->token_per_lines = line_tok_count;
		else if (map_config->token_per_lines != line_tok_count)
			return (close(fd), get_next_line(-42), free(line), false);
		map_config->rows++;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), true);
}

bool	parse_map(char *map, t_points **map_param)
{
	char	**split;
	char	*comma;
	size_t	j;

	j = 0;
	split = ft_split(map, ' ');
	if (!split)
		return (ft_free_double_char(split), false);
	while (split[j])
	{
		comma = ft_strchr(split[j], ',');
		if (comma)
		{
			*comma = '\0';
			map_param[0][j].Z_pos = ft_atoi(split[j]);
			map_param[0][j].color = ft_atoi_base(comma + 1, "0123456789ABCDEF");
		}
		else
		{
			map_param[0][j].Z_pos = ft_atoi(split[j]);
			map_param[0][j].color = 0xFFFFFF;
		}
		printf("%s ", split[j]);
		j++;
	}
		printf("\n");
	(void) map_param;
	return (true);
}
