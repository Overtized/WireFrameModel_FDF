/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:10:50 by mchanlia          #+#    #+#             */
/*   Updated: 2025/04/28 14:35:04 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	int				len;
	int				cursor;
	unsigned char	ch;

	i = 0;
	len = ft_strlen(s);
	cursor = -1;
	ch = c % 256;
	if (ch == '\0')
	{
		return ((char *)&s[len]);
	}
	while (s[i])
	{
		if (s[i] == ch)
			cursor = i;
		i++;
	}
	if ((unsigned char) ch == '\0')
		return ((char *)(&s [cursor]));
	if (len == 0 || cursor == -1)
		return (NULL);
	return ((char *)&s[cursor]);
}
