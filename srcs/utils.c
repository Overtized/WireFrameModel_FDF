/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:16:34 by mchanlia          #+#    #+#             */
/*   Updated: 2025/09/02 15:14:38 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_put_pixel(t_img_data *map, int x, int y, int color)
{
	char	*dst;
	dst = NULL;
	if (x >= 0 && x < X && y >= 0 && y < Y)
		dst = map->addr + (y * map->line_l + x * (map->bit_l / 8));
	*(unsigned int*)dst = color;
}
void	draw_line()
{
	
}