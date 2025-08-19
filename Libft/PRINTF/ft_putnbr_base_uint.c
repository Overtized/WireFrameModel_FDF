/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_uint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:38:03 by mchanlia          #+#    #+#             */
/*   Updated: 2025/05/18 23:46:11 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	ft_checkbase(char *base)
{
	size_t	baselen;
	size_t	i;

	i = 0;
	baselen = ft_strlen(base);
	if (!base || baselen < 2)
		return (false);
	if (ft_strchr(base, '+') || ft_strchr(base, '-'))
		return (false);
	while (i < baselen - 1)
	{
		if (ft_strchr(&base[i + 1], base[i]))
			return (false);
		i++;
	}
	return (true);
}

int	ft_putnbr_base_uint(unsigned int n, char *base, int fd)
{
	int					len;
	const unsigned int	baselen = ft_strlen(base);
	unsigned int		numb;

	if (!ft_checkbase(base))
		return (0);
	numb = n;
	len = 0;
	if (numb >= baselen)
		len += ft_putnbr_base_ulong(numb / baselen, base, fd);
	len += ft_putchar_int(base[numb % baselen], fd);
	return (len);
}
