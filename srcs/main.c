/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:21:44 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/26 18:53:56 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char *av[])
{
	t_map	map;

	if (ac != 2)
		return (ft_printf(1, "wrong args number, args should be 2\n"));
	if (!test_input(av[1], &map))
		return (ft_printf(1, "map is not valid \n"), 1);
	printf("%s\n\n", (map).map);
	free(map.map);
	// if (!parse_map(av[1], map))
	// 	return (ft_printf(1, "parsing error \n"), 1);
	ft_printf(1, "hello world\n");
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