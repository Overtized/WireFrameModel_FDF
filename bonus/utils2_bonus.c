/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:14:14 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/10 16:30:34 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf_bonus.h"

void	invert_color(int *color1, int *color2)
{
	*color1 = 0xFFFFFF - (*color1 & 0xFFFFFF);
	*color2 = 0xFFFFFF - (*color2 & 0xFFFFFF);
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

void	rotate_x(t_points *pt, t_mlx *mlx)
{
	float	y;
	float	z;
	float	radian;

	radian = (mlx->rot_x * PI) / 180.0;
	y = pt->y;
	z = pt->z;
	pt->y = y * cos(radian) - z * sin(radian);
	pt->z = y * sin(radian) + z * cos(radian);
}

void	rotate_y(t_points *pt, t_mlx *mlx)
{
	float	x;
	float	z;
	float	radian;

	radian = (mlx->rot_y * PI) / 180.0;
	x = pt->x;
	z = pt->z;
	pt->x = x * cos(radian) + z * sin(radian);
	pt->z = -x * sin(radian) + z * cos(radian);
}

void	rotate_z(t_points *pt, t_mlx *mlx)
{
	float	x;
	float	y;
	float	radian;

	radian = (mlx->rot_z * PI) / 180.0;
	x = pt->x;
	y = pt->y;
	pt->x = x * cos(radian) - y * sin(radian);
	pt->y = x * sin(radian) + y * cos(radian);
}
