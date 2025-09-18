/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:43:03 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/18 13:47:49 by mchanlia         ###   ########.fr       */
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
	if (key == I_KEY || key == T_KEY || key == G_KEY)
	{
		if (key == I_KEY)
			mlx->color_flag = !mlx->color_flag;
		else if (key == T_KEY)
			handle_z_zoom(mlx, 1.1);
		else if (key == G_KEY)
			handle_z_zoom(mlx, 0.9);
		mlx->redraw = true;
	}
	if (key == X_KEY || key == S_KEY || key == Z_KEY)
	{
		if (key == X_KEY)
			mlx->rot_x += 10;
		else if (key == S_KEY)
			mlx->rot_y += 10;
		else if (key == Z_KEY)
			mlx->rot_z += 10;
		mlx->redraw = true;
	}
	return (0);
}

static int	key_mlx1(int keycode, t_mlx *mlx)
{
	if (keycode == ESCAPE)
		mlx_loop_end(mlx->mlx_ptr);
	if (keycode == PLUS_SIGN)
		handle_zoom(mlx, 1.1);
	if (keycode == MINUS_SIGN)
		handle_zoom(mlx, 0.9);
	if (keycode == LEFT)
		handle_shift(mlx, 0, -10);
	if (keycode == RIGHT)
		handle_shift(mlx, 0, 10);
	if (keycode == DOWN)
		handle_shift(mlx, 10, 0);
	if (keycode == UP)
		handle_shift(mlx, -10, 0);
	if (keycode == P_KEY)
	{
		mlx->proj_type = !mlx->proj_type;
		mlx->redraw = true;
	}
	return (0);
}

int	key_mlx(int key, t_mlx *mlx)
{
	key_mlx1(key, mlx);
	key_mlx2(key, mlx);
	return (0);
}
