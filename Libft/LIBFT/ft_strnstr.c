/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:32:38 by mchanlia          #+#    #+#             */
/*   Updated: 2025/04/29 10:32:38 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
	{
		return ((char *)big);
	}
	while (big[i] != '\0' && i < len)
	{
		while (little[j] == big[i + j] && big [i + j] && ((i + j) < len))
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		else
		{
			j = 0;
		}
		i++;
	}
	return (0);
}
