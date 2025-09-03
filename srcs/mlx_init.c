/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:35:55 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/03 16:52:00 by mchanlia         ###   ########.fr       */
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

static void	render_grid(t_img_data *mp, t_map *map_cfg, t_points **mp_cds)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_cfg->rows)
	{
		j = 0;
		while (j < map_cfg->token_per_lines)
		{
			mp_cds[i][j].x = mp_cds[i][j].x * ZOOM;
			mp_cds[i][j].y = mp_cds[i][j].y * ZOOM;
			mp_cds[i][j].z = mp_cds[i][j].z * ZOOM - 100;
			mp_cds[i][j].x += SHIFT_OFFSET;
			mp_cds[i][j].y += SHIFT_OFFSET;
			mp_cds[i][j].z += SHIFT_OFFSET;
			j++;
		}
		i++;
	}
	draw_lines(mp, mp_cds, map_cfg);
}

static void	render_next_frame(t_map *map_cfg, t_points **map_cords, t_mlx *mx)
{
	t_img_data	*mp;

	mp = calloc(sizeof(t_img_data), 1);
	mp->img = mlx_new_image(mx->mlx_ptr, X, Y);
	mp->addr = mlx_get_data_addr(mp->img, &mp->bit_l, &mp->line_l, &mp->endian);
	render_grid(mp, map_cfg, map_cords);
	mlx_put_image_to_window(mx->mlx_ptr, mx->window, mp->img, X / 4, Y / 4);
	mlx_destroy_image(mx->mlx_ptr, mp->img);
	free(mp);
}

bool	mlx_setup(t_map *map_cfg, t_points **map_coords, t_mlx	*mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (free(mlx->mlx_ptr), false);
	mlx->window = mlx_new_window(mlx->mlx_ptr, X, Y, "Fdf");
	mlx_hook(mlx->window, ON_DESTROY, 0L, red_cross_mlx, mlx);
	mlx_key_hook(mlx->window, esc_mlx, mlx);
	render_next_frame(map_cfg, map_coords, mlx);
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
