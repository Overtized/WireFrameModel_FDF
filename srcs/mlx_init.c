/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:35:55 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/05 14:41:30 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	esc_mlx(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

static int	red_cross_mlx(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

static void	render_grid(t_img_data *mp, t_map *m_cg, t_points **m_cd, t_mlx *mx)
{
	int	i;
	int	j;

	i = 0;
	while (i < m_cg->rows)
	{
		j = 0;
		while (j < m_cg->token_per_lines)
		{
			m_cd[i][j] = project_iso(m_cd[i][j], m_cg, mx);
			j++;
		}
		i++;
	}
	draw_lines(mp, m_cd, m_cg);
}

static bool	render_next_frame(t_map *map_cfg, t_points **map_cords, t_mlx *mx)
{
	t_img_data	*mp;

	mp = calloc(sizeof(t_img_data), 1);
	if (!mp)
		return (false);
	mp->img = mlx_new_image(mx->mlx_ptr, X, Y);
	mp->addr = mlx_get_data_addr(mp->img, &mp->bit_l, &mp->line_l, &mp->endian);
	render_grid(mp, map_cfg, map_cords, mx);
	mlx_put_image_to_window(mx->mlx_ptr, mx->window, mp->img, 0, 0);
	mlx_destroy_image(mx->mlx_ptr, mp->img);
	free(mp);
	return (true);
}

bool	mlx_setup(t_map *map_cfg, t_points **map_coords, t_mlx	*mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (free(mlx->mlx_ptr), false);
	mlx->window = mlx_new_window(mlx->mlx_ptr, X, Y, "Fdf");
	if(mlx->window == NULL)
		return (free(mlx->mlx_ptr), false);
	mlx_hook(mlx->window, ON_DESTROY, 0L, red_cross_mlx, mlx);
	mlx_key_hook(mlx->window, esc_mlx, mlx);
	if (!render_next_frame(map_cfg, map_coords, mlx))
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->window);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		return (false);
	}
	mlx_loop(mlx->mlx_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	return (true);
}

// static void garbage (void)
// {
// 	// mlx_loop_hook(mlx->mlx_ptr, render_next_frame, mlx);
// 	// mlx_sync()
// 	// une fonction pour regrouper hook keyhook et loop si besoin place
// }
