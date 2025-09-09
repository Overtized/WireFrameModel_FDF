/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:14:14 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/09 18:03:16 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_mlx(int keycode, t_mlx *mlx)
{
	printf(" keycode = 0x%x\n", keycode);
	if (keycode == 0xff1b) // escape
		mlx_loop_end(mlx->mlx_ptr);
	if (keycode == 0x3d)
	{
		mlx->zoom *= 1.1;
		mlx->redraw = true;
	} // zoom +
	if (keycode == 0x2d)
	{
		mlx->zoom *= 0.9;
		mlx->redraw = true;
	} // zoom -
	// if (!render_frame(mlx))
	// {
	// 	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	// 	mlx_destroy_display(mlx->mlx_ptr);
	// 	free(mlx->mlx_ptr);
	// 	return (0);
	// }
	// if (keycode == 0xff52) // up
	// 	mlx->shift /= 1,1;
	// if (keycode == 0xff54) // down
	// 	mlx->shift /= 1,1;
	// if (keycode == 0xff53) // right
	// 	mlx->shift /= 1,1;
	// if (keycode == 0xff51) // left
	// 	mlx->shift /= 1,1;
	return (0);
}

int	red_cross_mlx(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}
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
	
void	shift(t_mlx *mx, int shift_x, int shift_y, int i)
{
	int	j;

	while (i < mx->map_cfg->rows)
	{
		j = 0;
		while (j < mx->map_cfg->token_per_lines)
		{
			mx->map_cds[i][j].x += shift_x;
			mx->map_cds[i][j].y += shift_y;
			j++;
		}
		i++;
	}
}
void	projection(t_mlx *mx)
{
	int	j;
	int	i;

	i = 0;
	while (i < mx->map_cfg->rows)
	{
		j = 0;
		while (j < mx->map_cfg->token_per_lines)
		{
			mx->map_cds[i][j] = project_iso(mx->map_cds[i][j], mx);
			j++;
		}
		i++;
	}
}
// static void	garbage(void)
// {
// 	// i = 0;
// 	// while (i < mx->map_cfg->rows)
// 	// {
// 	// 	j = 0;
// 	// 	while (j < mx->map_cfg->token_per_lines)
// 	// 	{
// 	// 		t_points pt = mx->map_cds[i][j];
// 	// 		printf("(%d,%d,%d)", pt.x, pt.y, pt.z);
// 	// 		j++;
// 	// 	}
// 	// 	i++;;
// 	// }
// }