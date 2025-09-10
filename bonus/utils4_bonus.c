/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:43:03 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/10 14:30:02 by mchanlia         ###   ########.fr       */
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

static int	key_mlx2(int keycode, t_mlx *mlx)
{
	if (keycode == 0x69)
	{
		mlx->color_flag = 1;
		mlx->redraw = true;
	} // i
	if (keycode == 0x6b)
	{
		mlx->color_flag = 0;
		mlx->redraw = true;
	} // k
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
	if (keycode == 0x70)
	{
		mlx->proj_type = 0;
		mlx->redraw = true;
	} // p
	if (keycode == 0x6c)
	{
		mlx->proj_type = 1;
		mlx->redraw = true;
	} // l
	return (0);
}

int	key_mlx(int key, t_mlx *mlx)
{
	key_mlx1(key, mlx);
	key_mlx2(key, mlx);
	return (0);
}
