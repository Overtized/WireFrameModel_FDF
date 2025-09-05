/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:14:14 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/05 14:22:11 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_points	*zoom_pt(t_points *pt, t_map *map, t_mlx *mlx)
{

	int	zoom_x;
	int	zoom_y;
	int zoom;

	zoom_x = X / map->token_per_lines;
	zoom_y = Y / map->rows;
	if (zoom_x < zoom_y)
		zoom = zoom_x;
	else
		zoom = zoom_y;
	if(map->rows < 100)
		zoom = zoom * 0.5;
	else if (map->rows >= 100)
		zoom = zoom * 0.75;
	pt->x = pt->x * zoom;
	pt->y = pt->y * zoom;
	pt->z = pt->z * (zoom * 0.04);
	mlx->zoom = zoom;
	return (pt);
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