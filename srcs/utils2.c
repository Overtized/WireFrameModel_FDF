/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:14:14 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/09 21:06:26 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
void	handle_zoom(t_mlx *mlx, double factor)
{
	mlx->zoom *= factor;
	mlx->redraw = true;
}
void	handle_shift(t_mlx *mlx, int x, int y)
{
		mlx->new_offset_x += x;
		mlx->new_offset_y += y;
		mlx->redraw = true;
}
int	key_mlx(int keycode, t_mlx *mlx)
{
	printf(" keycode = 0x%x\n", keycode);
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
	} // p
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
	
void	shift(t_points *pt, t_mlx *mlx)
{
	pt->x += mlx->offset_x + mlx->new_offset_x;
	pt->y += mlx->offset_y + mlx->new_offset_y;
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