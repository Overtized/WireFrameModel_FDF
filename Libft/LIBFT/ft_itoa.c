/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 08:52:54 by mchanlia          #+#    #+#             */
/*   Updated: 2025/05/06 08:52:54 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fillstring(long nbr, char *string, size_t digitscount)
{
	string[digitscount] = '\0';
	while (nbr > 0)
	{
		string[--digitscount] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (string);
}

static int	dcount(int n)
{
	size_t	nbdigits;
	long	digits;

	digits = n;
	nbdigits = 0;
	if (digits == 0)
		return (1);
	if (digits < 0)
		digits = -digits;
	while (digits > 0)
	{
		digits /= 10;
		nbdigits++;
	}
	return (nbdigits);
}

char	*ft_itoa(int n)
{
	size_t	digitscount;
	char	*string;
	long	nbr;
	int		minussign;

	minussign = 0;
	nbr = n;
	if (nbr == 0)
		return (ft_strdup("0"));
	if (nbr < 0)
	{
		nbr = -nbr;
		minussign = 1;
	}
	digitscount = dcount(nbr) + minussign;
	string = malloc(sizeof(char) * (digitscount + 1));
	if (!string)
		return (NULL);
	string = fillstring(nbr, string, digitscount);
	if (minussign)
		string[0] = '-';
	return (string);
}
