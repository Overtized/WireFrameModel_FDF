/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:35:36 by mchanlia          #+#    #+#             */
/*   Updated: 2025/05/12 19:35:36 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_int( const char *format, int fd)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (!format)
	{
		len += ft_putstr_int("(null)", fd);
		return (len);
	}
	while (format[i])
	{
		len += ft_putchar_int(format[i], fd);
		i++;
	}
	return (len);
}
