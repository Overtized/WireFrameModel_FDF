/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mx_struc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:06:10 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/10 18:38:24 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf_bonus.h"

void	init_mx_struct_bonus(t_mlx *mlx)
{
	if (mlx->map_cfg->rows < 100)
		mlx->zoom = 20;
	else if (mlx->map_cfg->rows >= 100)
		mlx->zoom = 1;
	if (mlx->map_cfg->rows < 100)
		mlx->zoom_z = 10;
	else if (mlx->map_cfg->rows >= 100)
		mlx->zoom_z = 0.5;
	mlx->redraw = true;
	mlx->img.img = NULL;
	mlx->new_offset_x = 0;
	mlx->new_offset_y = 0;
	mlx->color_flag = 0;
	mlx->proj_type = 1;
	mlx->rot_x = 0;
	mlx->rot_y = 0;
	mlx->rot_z = 0;
}
