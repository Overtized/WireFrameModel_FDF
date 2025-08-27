#ifndef FDF_H
#define FDF_H

#include "../Libft/My_libft.h"
#include "../minilibx-linux/mlx.h"
#include "math.h"

typedef struct	s_points
{
	int Z_pos;
	int	color;
}				t_points;
typedef struct	s_map
{
	int rows;
	int token_per_lines;
	t_points **map_coordonates;
}				t_map;
bool	test_input(char *av);
bool	check_hex_validity(char *buffer);
//
bool	init_map(char *file, t_map *map_config);
//
bool	handle_errors(int ac, char *av);
void	ft_free_structs(t_map *commands);
//
bool	parse_map(char *map, t_points **map_param);
#endif