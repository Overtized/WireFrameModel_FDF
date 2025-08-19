/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:05:36 by mchanlia          #+#    #+#             */
/*   Updated: 2025/05/10 09:05:36 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkargset(const char format)
{
	if (format == 'c' || format == 'p'
		|| format == 'd' || format == 'i'
		|| format == 'u' || format == 's'
		|| format == 'x' || format == 'X'
		|| format == '%')
		return (1);
	return (0);
}

static int	ft_checkskip(const char format)
{
	if (format == '-' || format == '+')
		return (1);
	if (ft_isdigit(format))
		return (1);
	return (0);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (ft_checkskip(format[i]))
				i++;
			if (ft_checkargset(format[i]))
				len += ft_putconverted(&format[i++], ap, fd);
		}
		else
			len += ft_putchar_int (format[i++], fd);
	}
	va_end (ap);
	return (len);
}
