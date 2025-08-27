/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:10:04 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/27 18:49:03 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	handle_errors(int ac, char *av)
{
	if (ac != 2)
	{
		ft_printf(1, "wrong args number, args should be 2\n");
		return (false);
	}
	if (!test_input(av))
	{
		ft_printf(1, "raw_map is not valid \n");
		return (false);
	}
	return(true);
}
