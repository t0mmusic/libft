/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:06:05 by jbrown            #+#    #+#             */
/*   Updated: 2022/01/28 14:25:31 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*	returns a trimmed-down copy of a string by removing 'set'
	from beginning and end of string. */

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	while (ft_strchr(set, s1[first]))
		first++;
	last = ft_strlen(s1);
	while (ft_strchr(set, s1[last]))
		last--;
	return (ft_substr(s1, first, last - first + 1));
}
