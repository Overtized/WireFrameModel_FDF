/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:47:45 by mchanlia          #+#    #+#             */
/*   Updated: 2025/05/02 14:47:45 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	lens1s2;
	size_t	i;

	i = 0;
	lens1s2 = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc((sizeof(char) * lens1s2) + 1);
	if (!new_str)
		return (NULL);
	while (i < lens1s2 - ft_strlen(s2))
	{
		new_str[i] = s1[i];
		i++;
	}
	while (i < lens1s2)
	{
		new_str[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
