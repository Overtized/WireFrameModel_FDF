/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:21:44 by mchanlia          #+#    #+#             */
/*   Updated: 2026/07/16 05:05:19 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char *av[])
{
	t_map		*map;
	t_points	**map_pt;
	t_mlx		*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx)); // allocation pointeur initial librairie graphique mlx
	if (!mlx)
		return (1);
	map = ft_calloc(1, sizeof(t_map)); // allocation de la structure de map
	if (!map)
		return (1);
	map_pt = NULL;
	if (!handle_errors(ac, av[1], map)) // initial check
		return (ft_free_map(map, mlx), 1);
	if (!init_map(av[1], map)) // filling of the map datastructure
		return (ft_printf(1, "init failed\n"), ft_free_map(map, mlx), 1);
	map_pt = allocate_map(map, map_pt); // mappt alloc
	if (map_pt == NULL)
		return (ft_free_structs(map, map_pt, mlx), 1);
	if (!load_map(map->map, map_pt, map)) // struct loading
		return (ft_printf(1, "parsing error \n"), 1);
	mlx->map_cds = map_pt;
	mlx->map_cfg = map;
	if (!mlx_setup(mlx)) // setup of the mlx graphical lib and main loop event
		return (ft_free_structs(map, map_pt, mlx), 1);
	return (ft_free_structs(map, map_pt, mlx), 0); // free funcs
}
