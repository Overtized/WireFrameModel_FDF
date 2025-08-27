/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:12:52 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/27 18:28:32 by mchanlia         ###   ########.fr       */
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
// bool	parse_map(char *map, t_map_cf *map_param, size_t map_len)
// {
// 	char	*line;
// 	char	**split;
// 	char	*comma;
// 	int		fd;
// 	int		tokens[map_len];
// 	size_t	i;

// 	i = 0;
// 	fd = open(map, O_RDONLY);
// 	if (fd == -1)
// 		return(perror("open fail \n"), false);
// 	printf("map len = %zu\n", map_len);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		split = ft_split(line, ' ');
// 		if (!split)
// 			return (ft_free_double_char(split), false);
// 		i = 0;
// 		while (split[i])
// 		{
// 			comma = ft_strchr(split[i], ',');
// 			if (comma)
// 				*comma = '\0';
// 			tokens[i] = ft_atoi(split[i]);
// 			printf("%s ", split[i]);
// 			i++;
// 		}
// 		printf("\n");
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	// tokens[i] = ft_atoi_base(line, "0123456789ABCDEF");
// 	close(fd);
// 	(void) map_param;
// 	return (true);
// }

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
		if(map_config->token_per_lines == 0)
			map_config->token_per_lines = line_tok_count;
		else if (map_config->token_per_lines != line_tok_count)
		{
			get_next_line(-42);
			free(line);
			return (ft_printf(1, "wrong map format\n"), false);
		}
		map_config->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	// printf ("\n%d\n", map_config->rows);
	// printf ("\n%d\n", map_config->token_per_lines);
	return (true);
	// fonction pour connaitre la longueur de chaque ligne
	// fonction pour conaitre le nombre de colonne
	// malloc du nombre de ligne
	// malloc du nonbre de colonne
}

// bool	parse_map(char *map, t_map_cf **map_param)
// {
// 	char	**split;
// 	char	*comma;
// 	size_t	j;

// 	j = 0;
// 	split = ft_split(map, ' ');
// 	if (!split)
// 		return (ft_free_double_char(split), false);
// 	while (split[j])
// 	{
// 		comma = ft_strchr(split[j], ',');
// 		if (comma)
// 		{
// 			*comma = '\0';
// 			map_param[0][j].Z_pos = ft_atoi(split[j]);
// 			map_param[0][j].color = ft_atoi_base(comma + 1, "0123456789ABCDEF");
// 		}
// 		else
// 		{
// 			map_param[0][j].Z_pos = ft_atoi(split[j]);
// 			map_param[0][j].color = 0xFFFFFF;
// 		}
// 		printf("%s ", split[j]);
// 		j++;
// 	}
// 		printf("\n");
// 	(void) map_param;
// 	return (true);
// }
