/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:38:03 by mchanlia          #+#    #+#             */
/*   Updated: 2025/05/12 19:38:03 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int fd)
{
	int	len;

	len = 0;
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (len + 11);
	}
	if (n < 0)
	{
		len += ft_putchar_int('-', fd);
		n = -n;
	}
	if (n > 9)
		len += ft_putnbr(n / 10, fd);
	len += ft_putchar_int(n % 10 + '0', fd);
	return (len);
}
