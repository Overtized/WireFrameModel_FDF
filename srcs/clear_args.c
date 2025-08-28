/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:20:01 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/28 19:41:27 by mchanlia         ###   ########.fr       */
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

static void	ft_free_args(t_points **map_params)
{
	t_points	*cursor;

	if (!map_params && !*map_params)
		return ;
	while (map_params && *map_params)
	{
		cursor = (*map_params)->next;
		free((*map_params));
		*map_params = cursor;
	}
	free((map_params));
}


void	ft_free_structs(t_map *map_config, t_points **map_params)
{
	if (map_config)
	{
		if (map_config->map_coordonates)
		{
			ft_free_args(map_config->map_coordonates);
		}
		free(map_config);
	}
	if (map_params)
	{
		ft_free_args(map_params);
	}
}

void	ft_safe_close(int *fd)
{
	if (*fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
}
