/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:46:54 by jbrown            #+#    #+#             */
/*   Updated: 2022/01/31 09:19:45 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	clears every element of a list given its first element.
	This function takes a 'delete' function as it's input
	paramater which is assumed to free the memory. */

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t;

	t = *lst;
	if (lst && del)
	{
		while (*lst)
		{
			t = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = t;
		}
	}
}
