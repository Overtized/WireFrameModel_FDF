/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:20:01 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/01 16:20:38 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_double_char(char **commands)
{
	int	i;

	i = 0;
	if (!commands && !*commands)
		return ;
	while (commands[i])
	{
		free (commands[i]);
		i++;
	}
	if (commands)
		free (commands);
}

static void	ft_free_args(t_map *map_config, t_points **map_params)
{
	int	i;

	i = 0;
	if (!map_params)
		return ;
	while (i < map_config->rows)
	{
		free((map_params[i]));
		i++;
	}
	free((map_params));
}


void	ft_free_map(t_map *map_config)
{
	if(map_config->map)
	{
		
		free(map_config->map);
	}
	if (map_config && map_config->map_coordonates)
	{
		ft_free_args(map_config, map_config->map_coordonates);
	}
	
	free(map_config);
}
void	ft_free_structs(t_map *map_config, t_points **map_coords, t_mlx *mlx)
{
	if (map_coords)
	{
		ft_free_args(map_config, map_coords);
	}
	if (map_config)
	{
		ft_free_map(map_config);
	}
	if (mlx)
	{
		if (mlx->mlx_ptr)
			free(mlx->mlx_ptr);
		else if (mlx->main_window)
			free(mlx->main_window);
	}
}

