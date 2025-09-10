/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:41:07 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/10 12:05:51 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_mp_bd	*init_bound(t_mp_bd *mp)
{
	mp->max_x = INT_MIN;
	mp->max_y = INT_MIN;
	mp->min_x = INT_MAX;
	mp->min_y = INT_MAX;
	return (mp);
}

void	check_map_bounds(t_mlx *mx, int *shift_x, int *shift_y, int i)
{
	int	j;
	t_mp_bd	mp;
	t_points p;

	init_bound(&mp);
	while (i < mx->map_cfg->rows)
	{
		j = 0;
		while (j < mx->map_cfg->token_per_lines)
		{
			p = mx->map_cds[i][j];
			if(p.x < mp.min_x)
				mp.min_x = p.x;
			if(p.x > mp.max_x)
				mp.max_x = p.x;
			if(p.y <  mp.min_y)
				mp.min_y = p.y;
			if(p.y > mp.max_y)
				mp.max_y = p.y;
			j++;
		}
		i++;
	}
	*shift_x = (X - (mp.max_x - mp.min_x)) / 2 - mp.min_x;
	*shift_y = (Y - (mp.max_y - mp.min_y)) / 2 - mp.min_y;
}

static void	shift(t_points *pt, t_mlx *mlx)
{
	pt->x += mlx->offset_x + mlx->new_offset_x;
	pt->y += mlx->offset_y + mlx->new_offset_y;
}

static void	zoom_parallel(t_points *pt, t_mlx *mlx)
{
	pt->x = pt->x * mlx->zoom;
	pt->y = pt->y * mlx->zoom;
	pt->z = pt->z * mlx->zoom;
}

void	draw(t_img_data *m, t_points first_pt, t_points second_pt, t_mlx *mlx)
{
	if (mlx->proj_type == 1)
	{
		first_pt = project_iso(first_pt, mlx);
		shift(&first_pt, mlx);
		second_pt = project_iso(second_pt, mlx);
		shift(&second_pt, mlx);
		ft_draw_line(m, first_pt, second_pt, 0);
	}
	else if (mlx->proj_type == 0)
	{
		zoom_parallel(&first_pt, mlx);
		shift(&first_pt, mlx);
		zoom_parallel(&second_pt, mlx);
		shift(&second_pt, mlx);
		ft_draw_line(m, first_pt, second_pt, 0);
	}
}
