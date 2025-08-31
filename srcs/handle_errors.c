/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:10:04 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/31 13:48:25 by mchanlia         ###   ########.fr       */
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
	return(true);
}
bool	test_int(char *buffer)
{
	char	**split;
	char	**comma_split;
	int	i;

	i = 0;
	split = ft_split(buffer, ' ');
	if (!split)
		return (ft_free_double_char(split), false);
	while (split[i])
	{
		comma_split = ft_split(split[i], ',');
		if (!comma_split)
			return (ft_free_double_char(comma_split), ft_free_double_char(split), false);
		if (ft_is_overflow(comma_split[0]))
			return (ft_free_double_char(comma_split), ft_free_double_char(split), false);
		ft_free_double_char(comma_split);
		i++;
	}
	ft_free_double_char(split);
	return (true);
}
