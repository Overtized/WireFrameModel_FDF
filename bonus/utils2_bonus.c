/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:14:14 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/10 12:13:11 by mchanlia         ###   ########.fr       */
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

int	red_cross_mlx(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

int	key_mlx(int keycode, t_mlx *mlx)
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

void	ft_put_pixel(t_img_data *map, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= X || y < 0 || y >= Y)
		return ;
	dst = NULL;
	if (x >= 0 && x < X && y >= 0 && y < Y)
		dst = map->addr + (y * map->line_l + x * (map->bit_l / 8));
	*(unsigned int *)dst = color;
}
