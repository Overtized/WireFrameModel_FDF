/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:10:19 by mchanlia          #+#    #+#             */
/*   Updated: 2025/04/29 11:10:19 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated_mem;

	if (nmemb == 0 || size == 0 || nmemb > ULONG_MAX / size)
		return (NULL);
	if ( nmemb * size > __SIZE_MAX__)
		return (NULL);
	allocated_mem = malloc(nmemb * size);
	if (!(allocated_mem))
		return (NULL);
	ft_bzero(allocated_mem, (nmemb * size));
	return (allocated_mem);
}

// int main(void)
// {
// 	calloc(10000000000, 123456789123456789);
// 	ft_calloc(10000000000, 123456789123456789);
// }
