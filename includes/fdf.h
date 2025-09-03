#ifndef FDF_H
#define FDF_H

#include "../Libft/My_libft.h"
#include "../minilibx-linux/mlx.h"
#include "math.h"

enum
{
	ON_DESTROY = 17,
	X = 1000,
	Y = 1000,
	ZOOM = 20,
	SHIFT_OFFSET = X / 6
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
	void *window;
}				t_mlx;
typedef struct	s_points
{
	int			x;
	int			y;
	int			z;
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
void	my_put_pixel(t_img_data *map, int x, int y, int color);
void	draw_line();
//
#endif