/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 10:00:49 by mchanlia          #+#    #+#             */
/*   Updated: 2025/08/15 10:09:02 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_double_char(char **commands)
{
	int	i;

	i = 0;
	if (!commands || !*commands)
		return ;
	while (commands[i])
	{
		free (commands[i]);
		i++;
	}
	if (commands)
		free (commands);
}
