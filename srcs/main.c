/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:21:44 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/29 11:48:35 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char *av[])
{
	t_map		*map;
	t_points	**map_pt;

	map_pt = NULL;
	map = ft_calloc(1, sizeof(t_map));
	if(!handle_errors(ac, av[1]))
		return (ft_free_map(map) , 1);
	if (!init_map(av[1], map))
	{
		ft_printf(1, "init failed\n");
		return(ft_free_map(map) , 1);
	}
	map_pt = allocate_map(map, map_pt);
	if (map_pt == NULL)
		return (ft_free_structs(map, map_pt), false);
	ft_printf(1, "number of row %d\n", map->rows);
	ft_printf(1, "number of token per line %d\n", map->token_per_lines);
	ft_printf(1, "hello world\n");
	ft_free_structs(map, map_pt);
	// if (!parse_map(av[1], map_pt))
	// 	return (ft_printf(1, "parsing error \n"), 1);
	// ft_printf(1, "hello world\n");
	// ft_free_structs(map, map_pt);
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