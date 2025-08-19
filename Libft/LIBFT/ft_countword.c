/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 09:57:48 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/15 09:58:00 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *str, char c)
{
	int	inword;
	int	wordcount;
	int	i;

	inword = 0;
	i = 0;
	wordcount = 0;
	while (str[i])
	{
		if (str[i] != c && inword == 0)
		{
			inword = 1;
			wordcount++;
		}
		else if (str[i] == c)
			inword = 0;
		i++;
	}
	return (wordcount);
}
