/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:16:34 by mchanlia          #+#    #+#             */
/*   Updated: 2026/07/16 05:00:24 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	ft_draw_line(t_img_data *m, t_points p1, t_points p2) // bresenham's algorithm
{
	t_draw_line	l;

	l.dx = ft_abs(p2.x - p1.x);
	l.dy = ft_abs(p2.y - p1.y);
	init_dir(p1, p2, &l.dir_x, &l.dir_y);
	l.error = l.dx - l.dy;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		ft_put_pixel(m, p1.x, p1.y, p1.color); // standard putpixel
		l.tmp_e = l.error * 2;
		if (l.tmp_e > -l.dy)
		{
			p1.x += l.dir_x;
			l.error -= l.dy;
		}
		if (l.tmp_e < l.dx)
		{
			p1.y += l.dir_y;
			l.error += l.dx;
		}
	}
	ft_put_pixel(m, p2.x, p2.y, p2.color); // standard putpixel
}

void	draw_iso(t_img_data *m, t_points **p, t_map *mp, t_mlx *mlx)
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
				draw(m, p[row][col], p[row][col + 1], mlx); // draw the point at location
			if (row < mp->rows -1)
				draw(m, p[row][col], p[row + 1][col], mlx); // draw the point at location
			col++;
		}
		row++;
	}
}

void	draw_parallel(t_img_data *m, t_points **p, t_map *mp, t_mlx *mlx)
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
				draw(m, p[row][col], p[row][col + 1], mlx);
			if (row < mp->rows -1)
				draw(m, p[row][col], p[row + 1][col], mlx);
			col++;
		}
		row++;
	}
}

t_points	project_iso(t_points pt, t_mlx *mlx)
{
	float		angle;
	float		xf;
	float		yf;
	t_points	scaled;

	scaled = pt;
	angle = (30.0 * PI) / 180.0; // iso is like dofus view a bended angle 
	scaled.x = pt.x * mlx->zoom; // apply scaling to the point
	scaled.y = pt.y * mlx->zoom;
	scaled.z = pt.z * (mlx->zoom / 4);
	xf = (float)(scaled.x - scaled.y) *cosf(angle); // compute over float not to loose precision
	yf = (float)(scaled.x + scaled.y) *sinf(angle) - (float)scaled.z;
	scaled.x = (int) xf;
	scaled.y = (int) yf;
	scaled.z = 0;
	return (scaled);
}
