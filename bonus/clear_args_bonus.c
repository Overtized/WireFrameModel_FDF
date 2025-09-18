/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:20:01 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/18 13:13:08 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf_bonus.h"

void	ft_free_double_char(char **commands)
{
	int	i;

	i = 0;
	if (!commands)
		return ;
	while (commands[i])
	{
		free (commands[i]);
		i++;
	}
	free (commands);
}

static void	ft_free_args(t_map *map_config, t_points **map_params)
{
	int	i;

	i = 0;
	if (!map_params || !map_config)
		return ;
	while (i < map_config->rows)
	{
		if (map_params[i])
			free((map_params[i]));
		i++;
	}
	free((map_params));
}

void	ft_free_map(t_map *map_config, t_mlx *mlx)
{
	if (!map_config)
		return ;
	if (map_config->map)
	{
		free(map_config->map);
	}
	free(map_config);
	if (mlx)
		free (mlx);
}

void	ft_free_structs(t_map *map_config, t_points **map_coords, t_mlx *mlx)
{
	if (map_coords)
	{
		ft_free_args(map_config, map_coords);
	}
	ft_free_map(map_config, mlx);
}

int	red_cross_mlx(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}
