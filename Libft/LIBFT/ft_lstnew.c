/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:24:04 by mchanlia          #+#    #+#             */
/*   Updated: 2025/05/08 10:24:04 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lstcpy;

	lstcpy = malloc(sizeof(t_list));
	if (!lstcpy)
		return (NULL);
	lstcpy->content = content;
	lstcpy->next = NULL;
	return (lstcpy);
}
