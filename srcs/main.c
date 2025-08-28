/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:21:44 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/28 20:16:27 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char *av[])
{
	t_map	*map;
	t_points **coordonates;


	map = ft_calloc(1, sizeof(t_map));
	coordonates = NULL;
	if(!handle_errors(ac, av[1]))
		return (ft_free_structs(map, coordonates) , 1);
	if (!init_map(av[1], map))
	{
		ft_printf(1, "init failed\n");
		return(ft_free_structs(map, coordonates), 1);
	}
	ft_free_structs(map, coordonates);
	ft_printf(1, "hello world\n");
	// if (!parse_map(av[1], coordonates))
	// 	return (ft_printf(1, "parsing error \n"), 1);
	// ft_printf(1, "hello world\n");
	// ft_free_structs(map, coordonates);
	// free(raw_map.raw_map);
	// ft_printf(1, "hello world\n");
	return (0);
}
// ranger dans un tableau de structure contenant tout les infos (position/
//couleur...).

// //• open, close, read, write,
// malloc, free, perror,
// strerror, exit.
// • All functions of the math
// library (-lm compiler option,
// man 3 math on some operating
// systems).
// • All functions of the MiniLibX
// library.
// • ft_printf or any equivalent
// YOU coded