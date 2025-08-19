/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:30:38 by mchanlia          #+#    #+#             */
/*   Updated: 2025/05/13 09:30:38 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putvp(void *ptr, char *base, int fd)
{
	int				len;
	unsigned long	ptrv;

	len = 0;
	if (ptr != 0)
	{
		ptrv = (unsigned long)ptr;
		len = write(1, "0x", 2);
		len += ft_putnbr_base_ulong(ptrv, base, fd);
	}
	else
		len = ft_putstr_int("(nil)", fd);
	return (len);
}
