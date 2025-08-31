/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:21:44 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/31 22:47:14 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char *av[])
{
	t_map		*map;
	t_points	**map_pt;
	void		*mlx_ptr;
	void		*main_window;

	map_pt = NULL;
	map = ft_calloc(1, sizeof(t_map));
	if(!handle_errors(ac, av[1], map))
		return (ft_free_map(map) , 1);
	if (!init_map(av[1], map))
		return(ft_printf(1, "init failed\n"), ft_free_map(map) , 1);
	map_pt = allocate_map(map, map_pt);
	if (map_pt == NULL)
		return (ft_free_structs(map, map_pt), false);
	if (!load_map(map->map, map_pt, map))
		return (ft_printf(1, "parsing error \n"), 1);
	mlx_ptr = mlx_init();
	main_window = mlx_new_window(mlx_ptr, 1000, 1000, "Hello World");
	mlx_loop(mlx_ptr);
	(void)main_window;
	
	ft_printf(1, "%s\n", map->map);
	ft_printf(1, "point X coordinates is  %d\n", map_pt[0][4].Z_pos);
	ft_printf(1, "number of row %d\n", map->rows);
	ft_printf(1, "number of token per line %d\n", map->token_per_lines);
	ft_printf(1, "hello world\n");
	ft_free_structs(map, map_pt);
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