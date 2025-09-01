/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:35:55 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/01 17:54:15 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	esc_mlx(int keycode, t_mlx *mlx)
{
	if(keycode == 65307)
		mlx_loop_end(mlx->mlx_ptr);
	return(0);
}
static int	red_cross_mlx(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	return(0);
}
static char *render_next_frame(t_map *map_cfg, t_points **map_cords, t_mlx *mlx)
{
	void	*img;
	char	*image;
	// faire une grille 

	img = mlx_new_image(mlx->mlx_ptr, 100, 100);
	
	// img = mlx_destroy_image();
	(void)map_cfg;
	(void)map_cords;
	return(image);
}

bool	mlx_setup(t_map *map_cfg, t_points **map_coords, t_mlx	*mlx)
{
	int i;
	char *img;

	i = 0;
	mlx->mlx_ptr = mlx_init();
	if(!mlx->mlx_ptr)
		return (false);
	mlx->main_window = mlx_new_window(mlx->mlx_ptr, 1920, 1080, "Hello World");
	mlx_hook(mlx->main_window, ON_DESTROY, 0L, red_cross_mlx, mlx);
	mlx_key_hook(mlx->main_window, esc_mlx, mlx);
	img = render_next_frame(map_cfg, map_coords, mlx);
	mlx_put_image_to_window(mlx->mlx_ptr,mlx->main_window, img, 200, 200);
	mlx_loop(mlx->mlx_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->main_window);
	mlx_destroy_display(mlx->mlx_ptr);
	
	return (true);
}
static void garbage (void)
{
	// mlx_loop_hook(mlx->mlx_ptr, render_next_frame, mlx);
	// mlx_sync()
	// une fonction pour regrouper hook keyhook et loop si besoin place
}
