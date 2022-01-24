/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:03:25 by jbrown            #+#    #+#             */
/*   Updated: 2022/01/24 17:20:27 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	unsigned int	i;
	t_list			*r;

	r = malloc(sizeof(*r) * (*lst));
	if (!r)
		return (r);
	i = 0;
	while (lst)
	{
		r->content = ft_lstnew(f(lst->content));
		r = r->next;
		lst = lst->next;
	}
	return (r);
}
