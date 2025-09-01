/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:35:55 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/01 20:09:36 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	esc_mlx(int keycode, t_mlx *mlx)
{
	if(keycode == 65307)
		mlx_loop_end(mlx->mlx_ptr);
	return(0);
}
static int	red_cross_mlx(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	return(0);
}
void	my_put_pixel(t_img_data *map, int x, int y, int color)
{
	char	*dst;
	dst = NULL;
	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
		dst = map->addr + (y * map->line_l + x * (map->bit_l / 8));
	*(unsigned int*)dst = color;
}
static void	render_next_frame(t_map *map_cfg, t_points **map_cords, t_mlx *mlx)
{
	t_img_data *mp;

	mp = calloc(sizeof(t_img_data), 1);
	// faire une grille 

	mp->img = mlx_new_image(mlx->mlx_ptr, 1920, 1080);
	mp->addr = mlx_get_data_addr(mp->img, &mp->bit_l, &mp->line_l, &mp->endian);
	
	(void)map_cfg;
	(void)map_cords;
	my_put_pixel(mp, 6, 6, 0x00FF0000);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->main_window, mp->img, 50, 50);
	mlx_destroy_image(mlx->mlx_ptr, mp->img);
	free(mp);
}

bool	mlx_setup(t_map *map_cfg, t_points **map_coords, t_mlx	*mlx)
{
	int i;
	
	i = 0;
	mlx->mlx_ptr = mlx_init();
	if(!mlx->mlx_ptr)
		return (free(mlx->mlx_ptr), false);
	mlx->main_window = mlx_new_window(mlx->mlx_ptr, 1920, 1080, "Hello World");
	mlx_hook(mlx->main_window, ON_DESTROY, 0L, red_cross_mlx, mlx);
	mlx_key_hook(mlx->main_window, esc_mlx, mlx);
	render_next_frame(map_cfg, map_coords, mlx);
	mlx_loop(mlx->mlx_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->main_window);
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
