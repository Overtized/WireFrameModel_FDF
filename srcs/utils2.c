/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:14:14 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/08 18:22:03 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_points	zoom_pt(t_points pt, t_mlx *mlx)
{
	t_points	tmp;

	tmp = pt;
	tmp.x = pt.x * mlx->zoom;
	tmp.y = pt.y * mlx->zoom;
	tmp.z = pt.z * (mlx->zoom * 0.5);
	tmp.color = pt.color;
	return (tmp);
}

t_points	*shift_pt(t_points *pt, t_map *map, t_mlx *mlx)
{
	int	shift_x;
	int	shift_y;
	int	width;
	int	height;

	width = map->token_per_lines;
	height = map->rows;
	shift_x = (X - width) / 2;
	shift_y = (Y - height) / 2;
	pt->x += shift_x;
	pt->y += shift_y;
	mlx->offset_x = shift_x;
	mlx->offset_y = shift_y;
	return (pt);
}

int	key_mlx(int keycode, t_mlx *mlx, t_map *map_cfg, t_points **map_coords)
{
	printf(" keycode = 0x%x\n", keycode);
	if (keycode == 0xff1b) // escape
		mlx_loop_end(mlx->mlx_ptr);
	if (keycode == 0x3d) // zoom +
		mlx->zoom += 1;
	if (keycode == 0x2d) // zoom -
		mlx->zoom -= 1;
	if (keycode == 0xffe1) // shiftkey
		return 0;
	// if (keycode == 0xff52) // up
	// 	mlx->shift /= 1,1;
	// if (keycode == 0xff54) // down
	// 	mlx->shift /= 1,1;
	// if (keycode == 0xff53) // right
	// 	mlx->shift /= 1,1;
	// if (keycode == 0xff51) // left
	// 	mlx->shift /= 1,1;
	if (!render_frame(map_cfg, map_coords, mlx))
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->window);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		return (0);
	}
	return (0);
}

int	red_cross_mlx(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}
