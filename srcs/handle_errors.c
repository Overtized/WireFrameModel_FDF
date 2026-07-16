/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:10:04 by mchanlia          #+#    #+#             */
/*   Updated: 2026/07/16 04:45:39 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	handle_errors(int ac, char *av, t_map *map)
{
	if (ac != 2) // classic arg check
	{
		ft_printf(1, "wrong args number, args should be 2\n");
		return (false);
	}
	if (!test_input(av, map)) // first check of the map data
	{
		ft_printf(1, "raw_map is not valid \n");
		return (false);
	}
	return (true);
}

bool	test_int(char *buffer)
{
	char	**splt;
	char	**com;
	int		i;

	i = 0;
	splt = ft_split(buffer, ' ');
	if (!splt)
		return (ft_free_double_char(splt), false);
	while (splt[i])
	{
		com = ft_split(splt[i], ',');
		if (!com || ft_is_overflow(com[0]))
		{
			ft_free_double_char(com);
			ft_free_double_char(splt);
			return (false);
		}
		ft_free_double_char(com);
		i++;
	}
	ft_free_double_char(splt);
	return (true);
}
