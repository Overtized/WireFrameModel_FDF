/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:35:55 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/01 15:40:31 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	esc_mlx(int keycode, t_mlx *mlx)
{
	if(keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->main_window);
		exit (0);
	}
	return(0);
}
static int	red_cross_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->main_window);
	exit (0);
}
// void render_next_frame(t_map *map_config, t_points **map_coordinates)
// {
	
// }

bool	mlx_setup(t_mlx	*mlx)
{
	mlx->mlx_ptr = mlx_init();
	if(!mlx->mlx_ptr)
		return (false);
	mlx->main_window = mlx_new_window(mlx->mlx_ptr, 1000, 1000, "Hello World");
	if(!mlx->main_window)
		return (false);
	mlx_hook(mlx->main_window, ON_DESTROY, 1L<<2, red_cross_mlx, mlx);
	mlx_key_hook(mlx->main_window, esc_mlx, mlx);
	// mlx_loop_hook(mlx->mlx_ptr, render_next_frame, mlx)
	mlx_loop(mlx->mlx_ptr);
	// mlx_sync()
	return (true);
}
