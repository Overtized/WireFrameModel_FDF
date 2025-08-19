/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftputchar_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:41:02 by mchanlia          #+#    #+#             */
/*   Updated: 2025/05/11 13:41:02 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_int(int c, int fd)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	write(fd, &ch, 1);
	return (1);
}
