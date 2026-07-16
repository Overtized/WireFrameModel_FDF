/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:35:55 by mchanlia          #+#    #+#             */
/*   Updated: 2026/07/16 05:03:59 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	trigger_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->window, ON_DESTROY, 0L, (void *)red_cross_mlx, mlx); // close window with X cross top right
	mlx_hook(mlx->window, 2, 1L << 0, (void *)key_mlx, mlx); // other hooks basic on no bonus
}

int	render_loop(t_mlx *mlx)
{
	if (mlx->redraw)
	{
		if (!render_frame(mlx)) // main rendering func
		{
			mlx_loop_end(mlx->mlx_ptr);
			return (1);
		}
		mlx->redraw = false;
	}
	return (0);
}

static void	render_grid(t_mlx *mx)
{
	int	i;
	int	shift_x;
	int	shift_y;

	i = 0;
	check_map_bounds(mx, &shift_x, &shift_y, i);
	mx->offset_x = shift_x;
	mx->offset_y = shift_y;
	if (mx->proj_type == 0) // which it is by default
		draw_iso(&mx->img, mx->map_cds, mx->map_cfg, mx);
}

bool	render_frame(t_mlx *mx)
{
	int	ret_v;

	if (mx->img.img)
		mlx_destroy_image(mx->mlx_ptr, mx->img.img); // destroy old image before creating a new one
	mx->img.img = mlx_new_image(mx->mlx_ptr, X, Y); // new image with size limits/parameters
	if (!mx->img.img)
		return (false);
	mx->img.addr = mlx_get_data_addr(mx->img.img,
			&mx->img.bit_l, &mx->img.line_l, &mx->img.endian); // storage of the image adress in the struct
	if (mx->img.addr == NULL)
		return (false);
	render_grid(mx);
	ret_v = mlx_put_image_to_window(mx->mlx_ptr, mx->window, mx->img.img, 0, 0); // send image to display
	if (ret_v == -1)
		return (false);
	return (true);
}	

bool	mlx_setup(t_mlx	*mlx)
{
	if (mlx->map_cfg->rows < 100) // default zoom for small map
		mlx->zoom = 20;
	else if (mlx->map_cfg->rows >= 100) // default zoom for big maps
		mlx->zoom = 1;
	mlx->redraw = true; // indicate render_loop to redraw on change
	mlx->img.img = NULL;
	mlx->new_offset_x = 0;
	mlx->new_offset_y = 0;
	mlx->proj_type = 0;
	mlx->mlx_ptr = mlx_init(); // initialisation of the main mlx pointer
	if (!mlx->mlx_ptr)
		return (false);
	mlx->window = mlx_new_window(mlx->mlx_ptr, X, Y, "Fdf"); // window creation
	if (!mlx->window)
		return (free(mlx->mlx_ptr), false);
	mlx_loop_hook(mlx->mlx_ptr, (void *)render_loop, mlx); // inf loop function here
	trigger_hooks(mlx); // keyboard hooks func
	mlx_loop(mlx->mlx_ptr); // inf loop here
	if (mlx->img.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img); // cleaning of  the mlx
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	return (true);
}
