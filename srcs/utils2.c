/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:12:52 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/25 20:26:44 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	check_hex_validity(char *buffer)
{
	char	*cursor;
	int	hex_len;
	char *tmp;

	hex_len = 0;
	cursor = buffer;
	tmp = cursor;
	while (1)
	{
		hex_len = 0;
		cursor = (ft_strchr(cursor, 'x'));
		if (!cursor)
			break;
		if (cursor == buffer || *(cursor - 1) != '0')
			return (false);
		cursor++;
		while (hex_len < 6 && ft_ishex((int)cursor[hex_len]))
			hex_len++;
		if (hex_len == 1)
			return (false);
		// printf("\t you are here\n\n");
		// printf("\t value is %c\n\n", cursor[hex_len]);
		if (cursor[hex_len] != '\0' && !ft_isspace((int)cursor[hex_len]))
			return (false);
		cursor+= hex_len;
	}
	return (true);
}
