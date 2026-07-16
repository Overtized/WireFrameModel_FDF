/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:14:14 by mchanlia          #+#    #+#             */
/*   Updated: 2026/07/16 05:00:41 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	red_cross_mlx(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

int	key_mlx(int keycode, t_mlx *mlx)
{
	if (keycode == ESCAPE)
		mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

void	ft_put_pixel(t_img_data *map, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= X || y < 0 || y >= Y) // safety bound checking
		return ;
	dst = NULL;
	if (x >= 0 && x < X && y >= 0 && y < Y)
		dst = map->addr + (y * map->line_l + x * (map->bit_l / 8));
	*(unsigned int *)dst = color;
}
