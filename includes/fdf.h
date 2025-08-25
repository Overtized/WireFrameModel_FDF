#ifndef FDF_H
#define FDF_H

#include "../Libft/My_libft.h"
#include "../minilibx-linux/mlx.h"
#include "math.h"

typedef struct	s_mlx
{
	// t_position tab[50];
}				t_mlx;
typedef struct	s_position
{
	int X_pos;
	int Y_pos;
	int Z_pos;
	int	color;
}				t_position;
typedef struct	s_map
{
	char *map;
}				t_map;
bool	test_input(char *map);
bool	check_hex_validity(char *buffer);
#endif