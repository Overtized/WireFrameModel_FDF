/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:35:55 by mchanlia          #+#    #+#             */
/*   Updated: 2026/07/13 14:17:36 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	trigger_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->window, ON_DESTROY, 0L, (void *)red_cross_mlx, mlx);
	mlx_hook(mlx->window, 2, 1L << 0, (void *)key_mlx, mlx);
}

int	render_loop(t_mlx *mlx)
{
	if (mlx->redraw)
	{
		if (!render_frame(mlx))
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
	if (mx->proj_type == 0)
		draw_iso(&mx->img, mx->map_cds, mx->map_cfg, mx);
}

bool	render_frame(t_mlx *mx)
{
	int	ret_v;

	if (mx->img.img)
		mlx_destroy_image(mx->mlx_ptr, mx->img.img);
	mx->img.img = mlx_new_image(mx->mlx_ptr, X, Y);
	if (!mx->img.img)
		return (false);
	mx->img.addr = mlx_get_data_addr(mx->img.img,
			&mx->img.bit_l, &mx->img.line_l, &mx->img.endian);
	if (mx->img.addr == NULL)
		return (false);
	render_grid(mx);
	ret_v = mlx_put_image_to_window(mx->mlx_ptr, mx->window, mx->img.img, 0, 0);
	if (ret_v == -1)
		return (false);
	return (true);
}	

bool	mlx_setup(t_mlx	*mlx)
{
	if (mlx->map_cfg->rows < 100)
		mlx->zoom = 20;
	else if (mlx->map_cfg->rows >= 100)
		mlx->zoom = 1;
	mlx->redraw = true;
	mlx->img.img = NULL;
	mlx->new_offset_x = 0;
	mlx->new_offset_y = 0;
	mlx->proj_type = 0;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (false);
	mlx->window = mlx_new_window(mlx->mlx_ptr, X, Y, "Fdf");
	if (!mlx->window)
		return (free(mlx->mlx_ptr), false);
	mlx_loop_hook(mlx->mlx_ptr, (void *)render_loop, mlx);
	trigger_hooks(mlx);
	mlx_loop(mlx->mlx_ptr);
	if (mlx->img.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	return (true);
}
