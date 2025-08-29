#ifndef FDF_H
#define FDF_H

#include "../Libft/My_libft.h"
#include "../minilibx-linux/mlx.h"
#include "math.h"

typedef struct	s_points
{
	int			Z_pos;
	int			color;
}				t_points;
typedef struct	s_map
{
	int rows;
	int token_per_lines;
	t_points **map_coordonates;
}				t_map;
bool	test_input(char *av);
//
bool	init_map(char *file, t_map *map_config);
//
bool	handle_errors(int ac, char *av);
void	ft_free_structs(t_map *commands, t_points **coordonates);
void	ft_free_map(t_map *map_config);
t_points	**allocate_map(t_map *gridsize, t_points **coordonates);
//
bool	parse_map(char *map, t_points **map_param);
#endif