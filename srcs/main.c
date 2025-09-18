/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:21:44 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/18 13:12:11 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char *av[])
{
	t_map		*map;
	t_points	**map_pt;
	t_mlx		*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		return (1);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (1);
	map_pt = NULL;
	if (!handle_errors(ac, av[1], map))
		return (ft_free_map(map, mlx), 1);
	if (!init_map(av[1], map))
		return (ft_printf(1, "init failed\n"), ft_free_map(map, mlx), 1);
	map_pt = allocate_map(map, map_pt);
	if (map_pt == NULL)
		return (ft_free_structs(map, map_pt, mlx), 1);
	if (!load_map(map->map, map_pt, map))
		return (ft_printf(1, "parsing error \n"), 1);
	mlx->map_cds = map_pt;
	mlx->map_cfg = map;
	if (!mlx_setup(mlx))
		return (ft_free_structs(map, map_pt, mlx), 1);
	return (ft_free_structs(map, map_pt, mlx), 0);
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