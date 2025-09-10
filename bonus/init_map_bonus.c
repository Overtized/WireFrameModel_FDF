/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:12:52 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/10 19:02:06 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf_bonus.h"

static int	get_token_number(char *line)
{
	int		i;
	int		token;
	size_t	len;
	char	**split;
	char	*com;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	token = 0;
	i = 0;
	split = ft_split(line, ' ');
	if (!split)
		return (ft_free_double_char(split), -1);
	while (split[i])
	{
		com = strchr(split[i], ',');
		if (com)
			*com = '\0';
		token ++;
		i++;
	}
	ft_free_double_char(split);
	return (token);
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
				i--;
			}
			free(map_point);
			return (NULL);
		}
		i++;
	}
	return (map_point);
}

bool	init_map(char *raw_map, t_map *map_config)
{
	int		fd;
	char	*line;
	int		line_tok_count;

	line_tok_count = 0;
	fd = open(raw_map, O_RDONLY);
	if (fd == -1)
		return (perror("open failed\n"), false);
	line = get_next_line(fd);
	while (line)
	{
		line_tok_count = get_token_number(line);
		if (line_tok_count == -1)
			return (close(fd), get_next_line(-42), free(line), false);
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

static void	load_struct(char **split, t_points **map_param, int i)
{
	char	*com;
	int		j;
	char	*hex;

	hex = "0123456789ABCDEF";
	j = 0;
	while (split && split[j])
	{
		map_param[i][j].z = 0;
		map_param[i][j].color = 0xFFFFFF;
		if (split[j])
		{
			com = ft_strchr(split[j], ',');
			map_param[i][j].z = ft_atoi(split[j]);
			if (com)
				map_param[i][j].color = ft_atoi_base(str_toupper(com + 3), hex);
		}
		map_param[i][j].x = j;
		map_param[i][j].y = i;
		j++;
	}
}

bool	load_map(char *map, t_points **map_param, t_map *map_struct)
{
	char	**split;
	char	**lines;
	int		i;

	i = 0;
	lines = ft_split(map, '\n');
	if (!lines)
		return (ft_free_double_char(lines), false);
	while (i < map_struct->rows)
	{
		split = ft_split(lines[i], ' ');
		if (!split)
			return (ft_free_double_char(split), false);
		load_struct(split, map_param, i);
		ft_free_double_char(split);
		i++;
	}
	ft_free_double_char(lines);
	return (true);
}
