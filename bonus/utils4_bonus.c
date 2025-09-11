/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:43:03 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/11 11:33:16 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf_bonus.h"

static void	handle_zoom(t_mlx *mlx, double factor)
{
	mlx->zoom *= factor;
	if (mlx->zoom < 1)
		mlx->zoom = 1;
	else if (mlx->zoom > 1000)
		mlx->zoom = 1000;
	mlx->redraw = true;
}

static void	handle_shift(t_mlx *mlx, int x, int y)
{
	mlx->new_offset_x += x;
	mlx->new_offset_y += y;
	mlx->redraw = true;
}

static int	key_mlx2(int key, t_mlx *mlx)
{
	if (key == 0x69 || key == 0x6b || key == 0x74 || key == 0x67)
	{
		if (key == 0x69)
			mlx->color_flag = 1;
		else if (key == 0x6b)
			mlx->color_flag = 0;
		else if (key == 0x74)
			mlx->zoom_z *= 1.1;
		else if (key == 0x67)
			mlx->zoom_z *= 0.9;
		mlx->redraw = true;
	} // i k t g
	if (key == 0x78 || key == 0x73 || key == 0x7a )
	{
		if (key == 0x78)
			mlx->rot_x += 10;
		else if (key == 0x73)
			mlx->rot_y += 10;
		else if ( key == 0x7a)
			mlx->rot_z += 10;
		mlx->redraw = true;
	} // x y z
	return (0);
}

static int	key_mlx1(int keycode, t_mlx *mlx)
{
	if (keycode == 0xff1b) // escape
		mlx_loop_end(mlx->mlx_ptr);
	if (keycode == 0x3d)
		handle_zoom(mlx, 1.1); // zoom +
	if (keycode == 0x2d)
		handle_zoom(mlx, 0.9); // zoom -
	if (keycode == 0xff52) // up
		handle_shift(mlx, 0, -10);
	if (keycode == 0xff54) // down
		handle_shift(mlx, 0, +10);
	if (keycode == 0xff53) // right
		handle_shift(mlx, 10, 0);
	if (keycode == 0xff51) // left
		handle_shift(mlx, -10, 0);
	if (keycode == 0x70 || keycode == 0x6c)
	{
		if (keycode == 0x70)
			mlx->proj_type = 0;
		else if (keycode == 0x6c)
			mlx->proj_type = 1;
		mlx->redraw = true;
	} // p l
	return (0);
}

int	key_mlx(int key, t_mlx *mlx)
{
	key_mlx1(key, mlx);
	key_mlx2(key, mlx);
	return (0);
}
