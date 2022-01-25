/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:03:25 by jbrown            #+#    #+#             */
/*   Updated: 2022/01/25 12:52:47 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tlst;
	t_list	*nlst;

	if (!lst || !f || !del)
		return (NULL);
	tlst = ft_lstnew(f(lst->content));
	if (!flst)
		return (NULL);
	nlst = flist->next
	while (lst)
	{
		nlst->content = ft_lstnew(f(lst->content));
		if (!nlst)
			ft_lstdelone(nlst, del);
		else
		{
			tlst = nlst;
			nlst = nlst->next;
		}
		lst = lst->next;
	}
	return (tlst);
}
