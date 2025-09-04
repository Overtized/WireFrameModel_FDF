/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:31:13 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/04 19:46:23 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef PI
#  define PI 3.14159265358979323846
# endif
# include "../Libft/My_libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>

enum
{
	ON_DESTROY = 17,
	X = 1000,
	Y = 1000,
};
typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		bit_l;
	int		line_l;
	int		endian;
}				t_img_data;
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window;
	int		zoom;
	int		offset_x;
	int		offset_y;
}				t_mlx;
typedef struct s_points
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_points;
typedef struct s_map
{
	int			rows;
	int			token_per_lines;
	char		*map;
}				t_map;
bool		test_input(char *map, t_map *map_strct);
bool		test_int(char *buffer);
//
bool		init_map(char *file, t_map *map_config);
bool		load_map(char *map, t_points **map_param, t_map *map_struct);
//
void		ft_free_map(t_map *map_config);
void		ft_free_structs(t_map *map_config, t_points **map_coords);
bool		handle_errors(int ac, char *av, t_map *map);
//
bool		mlx_setup(t_map *map_cfg, t_points **map_coords, t_mlx	*mlx);
void		ft_put_pixel(t_img_data *map, int x, int y, int color);
void		draw_lines(t_img_data *m, t_points **p, t_map *mpm);
t_points	project_iso(t_points pt, t_map *map, t_mlx *mlx);
t_points	**allocate_map(t_map *gridsize, t_points **coordonates);
t_points	*zoom_pt(t_points *pt, t_map *map, t_mlx *mlx);
t_points	*shift_pt(t_points *pt, t_map *map, t_mlx *mlx);
//
#endif