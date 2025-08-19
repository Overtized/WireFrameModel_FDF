/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:39:23 by mchanlia          #+#    #+#             */
/*   Updated: 2025/05/08 15:39:23 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lstcp;

	if (!lst || !f)
		return ;
	lstcp = lst;
	while (lstcp)
	{
		f(lstcp->content);
		lstcp = lstcp->next;
	}
}
