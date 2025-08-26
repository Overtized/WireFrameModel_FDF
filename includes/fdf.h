#ifndef FDF_H
#define FDF_H

#include "../Libft/My_libft.h"
#include "../minilibx-linux/mlx.h"
#include "math.h"

typedef struct	s_mlx
{
	
}				t_mlx;
typedef struct	s_map
{
	int X_pos;
	int Y_pos;
	int Z_pos;
	int	color;
	char *map;
}				t_map;
bool	test_input(char *map, t_map *map_cf);
bool	check_hex_validity(char *buffer);
bool	parse_map(char *map, t_map **map_params);
#endif