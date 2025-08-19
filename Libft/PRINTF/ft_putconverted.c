/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putconverted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:02:22 by mchanlia          #+#    #+#             */
/*   Updated: 2025/05/27 22:13:23 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putconverted(const char *format, va_list ap, int fd)
{
	size_t	i;

	i = 0;
	if (format[i] == 'c')
		return (ft_putchar_int(va_arg(ap, int), fd));
	else if (format[i] == 's')
		return (ft_putstr_int(va_arg(ap, char *), fd));
	else if (format[i] == 'p')
		return (ft_putvp(va_arg(ap, void *), "0123456789abcdef", fd));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_putnbr(va_arg(ap, int), fd));
	else if (format[i] == 'u')
		return (ft_putnbr_base_uint(va_arg(ap, unsigned int),
				"0123456789", fd));
	else if (format[i] == 'x')
		return (ft_putnbr_base_uint(va_arg(ap, unsigned int),
				"0123456789abcdef", fd));
	else if (format[i] == 'X')
		return (ft_putnbr_base_uint(va_arg(ap, unsigned int),
				"0123456789ABCDEF", fd));
	else if (format[i] == '%')
		return (ft_putchar_int('%', fd));
	return (-1);
}
