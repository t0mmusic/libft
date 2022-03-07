/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:10:25 by jbrown            #+#    #+#             */
/*   Updated: 2022/01/28 16:04:36 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	copies 'n' elements from one location to another. To factor for overlapping
	memory, this function checks to see if the destination pointer is ahead
	of the source. If it is, it will copy the elements starting from the end. */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (dst > src)
	{
		i = (int) len - 1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int) len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}
