/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:10:04 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/03 16:44:45 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	handle_errors(int ac, char *av, t_map *map)
{
	if (ac != 2)
	{
		ft_printf(1, "wrong args number, args should be 2\n");
		return (false);
	}
	if (!test_input(av, map))
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
		if (!com)
			return (ft_free_double_char(com), ft_free_double_char(splt), false);
		if (ft_is_overflow(com[0]))
			return (ft_free_double_char(com), ft_free_double_char(splt), false);
		ft_free_double_char(com);
		i++;
	}
	ft_free_double_char(splt);
	return (true);
}
