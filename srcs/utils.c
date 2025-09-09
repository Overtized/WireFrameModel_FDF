/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:16:34 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/09 17:10:57 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

static void	init_dir(t_points p1, t_points p2, int *dir_x, int *dir_y)
{
	if (p1.x < p2.x)
		*dir_x = 1;
	else
		*dir_x = -1;
	if (p1.y < p2.y)
		*dir_y = 1;
	else
		*dir_y = -1;
}

static void	ft_draw_line(t_img_data *m, t_points p1, t_points p2, int tmp_e)
{
	int	dx;
	int	dy;
	int	dir_x;
	int	dir_y;
	int	error;

	dx = ft_abs(p2.x - p1.x);
	dy = ft_abs(p2.y - p1.y);
	init_dir(p1, p2, &dir_x, &dir_y);
	error = dx - dy;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		ft_put_pixel(m, p1.x, p1.y, p1.color);
		tmp_e = error * 2;
		if (tmp_e > -dy)
		{
			p1.x += dir_x;
			error -= dy;
		}
		if (tmp_e < dx)
		{
			p1.y += dir_y;
			error += dx;
		}
	}
}

void	draw_lines(t_img_data *m, t_points **p, t_map *mp)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < mp->rows)
	{
		col = 0;
		while (col < mp->token_per_lines)
		{
			if (col < mp->token_per_lines - 1)
				ft_draw_line(m, p[row][col], p[row][col + 1], 0);
			if (row < mp->rows -1)
				ft_draw_line(m, p[row][col], p[row + 1][col], 0);
			col++;
		}
		row++;
	}
}

t_points	project_iso(t_points pt, t_mlx *mlx)
{
	float	angle;
	float	xf;
	float	yf;
	t_points scaled;

	scaled = pt;
	angle = (30.0 * PI) / 180.0;
	scaled.x = pt.x * mlx->zoom;
	scaled.y = pt.y * mlx->zoom;
	scaled.z = pt.z * mlx->zoom;
	xf = (float)(scaled.x - scaled.y) *cosf(angle);
	yf = (float)(scaled.x + scaled.y) *sinf(angle) - (float)scaled.z;
	scaled.x = (int) xf;
	scaled.y = (int) yf;
	scaled.z = 0;
	return (scaled);
}
