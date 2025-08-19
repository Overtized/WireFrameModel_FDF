/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:35:57 by mchanlia          #+#    #+#             */
/*   Updated: 2025/05/12 19:35:57 by mchanlia         ###   ########.fr       */
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

int	ft_putnbr_base(int n, char *base, int fd)
{
	int			len;
	const int	baselen = ft_strlen(base);
	long		numb;

	if (!ft_checkbase(base))
		return (0);
	numb = n;
	len = 0;
	if (numb < 0)
	{
		len += ft_putchar_int('-', fd);
		numb = -numb;
	}
	if (numb >= baselen)
		len += ft_putnbr_base(numb / baselen, base, fd);
	len += ft_putchar_int(base[numb % baselen], fd);
	return (len);
}
// a voir si len a bien la bonne valeur si bug