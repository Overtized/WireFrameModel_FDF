/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:50:44 by mchanlia          #+#    #+#             */
/*   Updated: 2025/05/08 15:50:44 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstcp;
	t_list	*temp;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	lstcp = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		temp = ft_lstnew(new_content);
		if (!temp)
		{
			del(new_content);
			ft_lstclear(&lstcp, del);
			return (NULL);
		}
		ft_lstadd_back(&lstcp, temp);
		lst = lst->next;
	}
	return (lstcp);
}
