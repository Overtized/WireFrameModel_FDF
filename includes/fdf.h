#ifndef FDF_H
#define FDF_H

#include "../Libft/My_libft.h"
#include "../minilibx-linux/mlx.h"
#include "math.h"

enum
{
	ON_DESTROY = 17
};
typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bit_l;
	int		line_l;
	int		endian;
}				t_img_data;
typedef struct	s_mlx
{
	void *mlx_ptr;
	void *main_window;
}				t_mlx;
typedef struct	s_points
{
	int			Z_pos;
	int			color;
}				t_points;
typedef struct	s_map
{
	int rows;
	int token_per_lines;
	char *map;
	t_points **map_coordonates;
}				t_map;
bool	test_input(char *map, t_map *map_strct);
bool	test_int(char *buffer);
//
bool	init_map(char *file, t_map *map_config);
bool	load_map(char *map, t_points **map_param, t_map *map_struct);
//
bool	handle_errors(int ac, char *av, t_map *map);
void	ft_free_structs(t_map *map_config, t_points **map_coords, t_mlx *mlx);
void	ft_free_map(t_map *map_config);
t_points	**allocate_map(t_map *gridsize, t_points **coordonates);
//
bool	mlx_setup(t_map *map_cfg, t_points **map_coords, t_mlx	*mlx);

//
#endif