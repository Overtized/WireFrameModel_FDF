/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:31:13 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/11 11:32:27 by mchanlia         ###   ########.fr       */
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
typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bit_l;
	int		line_l;
	int		endian;
}				t_img_data;
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
typedef struct s_mlx
{
	t_points	**map_cds;
	t_img_data	img;
	t_map		*map_cfg;
	void		*mlx_ptr;
	void		*window;
	int			offset_x;
	int			offset_y;
	int			new_offset_x;
	int			new_offset_y;
	int			proj_type;
	float		zoom;
	bool		redraw;
}				t_mlx;
typedef struct s_mp_bd
{
	int	min_x;
	int	min_y;
	int	max_x;
	int	max_y;
}	t_mp_bd;
typedef struct s_draw_line
{
	int	dx;
	int	dy;
	int	dir_x;
	int	dir_y;
	int	error;
	int	tmp_e;
}	t_draw_line;
bool		test_input(char *map, t_map *map_strct);
bool		test_int(char *buffer);
//
bool		init_map(char *file, t_map *map_config);
bool		load_map(char *map, t_points **map_param, t_map *map_struct);
t_points	**allocate_map(t_map *gridsize, t_points **coordonates);
//
void		ft_free_map(t_map *map_config);
void		ft_free_structs(t_map *map_config, t_points **map_coords);
bool		handle_errors(int ac, char *av, t_map *map);
//
bool		mlx_setup( t_mlx	*mlx);
bool		render_frame(t_mlx *mx);
int			key_mlx(int keycode, t_mlx *mlx);
int			red_cross_mlx(t_mlx *mlx);
void		ft_put_pixel(t_img_data *map, int x, int y, int color);
void		check_map_bounds(t_mlx *mx, int *shift_x, int *shift_y, int i);
void		draw_iso(t_img_data *m, t_points **p, t_map *mp, t_mlx *mlx);
void		draw(t_img_data *m, t_points a, t_points b, t_mlx *mlx);
void		ft_draw_line(t_img_data *m, t_points p1, t_points p2);
void		draw_parallel(t_img_data *m, t_points **p, t_map *mp, t_mlx *mlx);
t_points	project_iso(t_points pt, t_mlx *mlx);
//
#endif