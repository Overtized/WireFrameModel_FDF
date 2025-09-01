/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:51:18 by mchanlia          #+#    #+#             */
/*   Updated: 2025/04/23 15:14:20 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_check(const char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		*sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	return (i);
}

static int	ft_check_baselen(char *base)
{
	int	i;
	int	j;
	int	baselen;

	i = 0;
	j = 0;
	baselen = ft_strlen(base);
	if (baselen < 2)
		return (0);
	while (i < baselen)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == 32 || base[i] >= 126)
			return (0);
		while (j < baselen)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_check_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *nptr, char	*base)
{
	int	i;
	int	result;
	int	sign;
	int	val;
	int	baselen;

	i = 0;
	if (!ft_check_baselen(base) || nptr[i] == '\0' || !base)
		return (0);
	val = 0;
	result = 0;
	sign = 1;
	baselen = ft_strlen(base);
	i = ft_str_check(nptr, &sign);
	while (nptr[i])
	{
		val = ft_check_in_base(base, nptr[i]);
		if (val == -1)
			break ;
		result = result * baselen + val;
		i++;
	}
	return (result * sign);
}
